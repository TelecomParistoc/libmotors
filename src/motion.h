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
void setPosition(int x, int y);


void addPointInPath(int x, int y, int goalAngle, void (*callback)(void));

void clearPath();

#endif
