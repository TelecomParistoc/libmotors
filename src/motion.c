#include <stdlib.h>
#include <stdio.h>
#include "timing.h"
#include "queue.h"

#define DIST_TOLERANCE 3 // mm
#define ANGLE_TOLERANCE 2 // deg

struct pathPoint {
	int x;
	int y;
	int goal_heading;
	void (*callback)(void);
};

static pthread_t eomThread; // endOfMoveThread structure
static int eomThreadStarted = 0; // 1 if endOfMoveThread has been started, 0 otherwise

static int goalDist;
static void (*distCallback)(void) = NULL;
static int currentDirection = DIR_NONE;

static int goalHeading;
static void (*headingCallback)(void) = NULL;

void endOfMoveThread() {
	int lastDistance = 0;
	int lastHeading = -1;

	while(1) {
		if(distCallback != NULL) {
			int dist = getDistance();
			if(abs(dist-goalDist) <= DIST_TOLERANCE && lastDistance == dist) {
				distCallback();
				distCallback = NULL;
				currentDirection = DIR_NONE;
			}
			lastDistance = dist;
		}
		if(headingCallback != NULL) {
			int heading = getHeading();
			int error = abs(heading - goalHeading) <= 180 ?
				abs(heading - goalHeading) : 360 - abs(heading - goalHeading);

			if(error <= ANGLE_TOLERANCE && lastHeading == heading) {
				headingCallback();
				headingCallback = NULL;
			}
			lastHeading = heading;
		}
		waitFor(200);
	}
}

void move(int distance, void (*callback)(void)) {
	if(distance == 0) {
		currentDirection = DIR_NONE;
		if(callback != NULL)
			callback();
		return;
	}

	goalDist = getDistance() + distance;
	distCallback = callback;
	setGoalDistance(goalDist);

	// if a callback has been specified, start endOfMoveThread if not started yet
	if(callback != NULL && !eomThreadStarted) {
		if(pthread_create(&eomThread, NULL, endOfMoveThread, NULL))
			printf("ERROR : cannot create end of move thread\n");
		else
			eomThreadStarted = 1;
	}

	// update current direction
	currentDirection = distance > 0 ? DIR_FORWARD : DIR_BACKWARD;
}

void turn(int heading, void (*callback)(void)) {
	goalHeading = heading;
	headingCallback = callback;
	setGoalHeading(heading);

	// if a callback has been specified, start endOfMoveThread if not started yet
	if(callback != NULL && !eomThreadStarted) {
		if(pthread_create(&eomThread, NULL, endOfMoveThread, NULL))
			printf("ERROR : cannot create end of move thread\n");
		else
			eomThreadStarted = 1;
	}
}

int getDirection() {
	return currentDirection;
}
