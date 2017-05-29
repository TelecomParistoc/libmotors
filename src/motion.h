#ifndef MOTION_H
#define MOTION_H

/* move of the given distance in mm, forward or backward (according to distance sign)
 * when the goal distance has been reached, callback is called if not NULL */
void move(int distance, void (*callback)(void));

/* turn to the given heading (absolute) in deg from 0 to 360 counterclockwise
 * when the goal heading has been reached, callback is called if not NULL */
void turn(int heading, void (*callback)(void));

/* returns the current moving direction */
#define DIR_NONE 0
#define DIR_FORWARD 1
#define DIR_BACKWARD 2
int getDirection();

/* set current absolute location of the robot (x, y in mm) */
void setPosition(float x, float y);

/* turn toward (x, y), go there then turn to goalAngle. Robot will try to minimize
 * rotation at the end of the movement so it will go forward or backward accordingly.
 * If no goalAngle is specified, robot will try to minimize start rotation and
 * go backward or forward accordingly. Function is non-blocking.
 *          x : x absolute coordinate in mm
 *          y : y absolute coordinate in mm
 *  goalAngle : final heading ( >= 0 ) at goal location, or -1 if don't care
 *   callback : a function like void f() {...} called when the move is over */
void moveTo(int x, int y, int goalAngle, void (*callback)(void));

/* queue a move to be executed by moveTo (see above for more info). If there's no
 * previously queued move, start the move directly. */
void addPointInPath(int x, int y, int goalAngle, void (*callback)(void));

/* removes all queued moves but does not stop current move. Callback of current
 * move won't be called. */
void clearPath();

#endif
