#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "timing.h"
#include "queue.h"

// return absolute value of the difference between two angle (0-360)
#define angleDiff(a, b) (abs(a-b) <= 180 ? abs(a-b) : 360 - abs(a-b))

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
// global variables used by move function (and callback system)
static int goalDist;
static void (*distCallback)(void) = NULL;
static int currentDirection = DIR_NONE;
// global variables used by turn function (and callback system)
static int goalHeading;
static void (*headingCallback)(void) = NULL;
// global variables used by moveTo function (and callback system)
static int moveToAngle, moveToDist;
static void (*moveToCallback)(void) = NULL;

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
			if(angleDiff(heading, goalHeading) <= ANGLE_TOLERANCE && lastHeading == heading) {
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

static void translationDone() {
	if(moveToAngle != -1)
		turn(moveToAngle, moveToCallback);
	else if(moveToCallback != NULL)
		moveToCallback();
}
static void startRotationDone() {
	move(moveToDist, translationDone);
}

void moveTo(int x, int y, int goalAngle, void (*callback)(void)) {
	// compute coordinates of the start to end vector
	int deltaX = x - getPosX(), deltaY = y - getPosY();
	// compute heading the robot should have to go to its destination forward
	double angle = atan2(deltaY, deltaX)*180.0/M_PI - 90;
	while(angle >= 360) angle -= 360;
	while(angle < 0) angle += 360;

	if(goalAngle != -1) { // if a goal angle has been specified
		// decide if robot should be forward or backward, minimizing end rotation
		if(angleDiff(angle, goalAngle) > 90) {
			angle = 180 + angle;
			if(angle >= 360)
				angle -= 360;
		}
	} else { // no goal angle specified : minimize start rotation
		int heading = getHeading();
		if(angleDiff(heading, angle) > 90) {
			angle = 180 + angle;
			if(angle >= 360)
				angle -= 360;
		}
	}
	// save distance and end angle then start to movement
	moveToDist = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	moveToAngle = goalAngle;
	turn(angle, startRotationDone);
}
