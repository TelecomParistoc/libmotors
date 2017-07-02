# libmotors JS binding #

This library provides high-level control over robot's motor controller,
in javascript with nodeJS.

## Install ##

Install of the JS binding is done during libmotors install. Check out main README
for instructions.

## Usage ##

To use it, after having installed libmotors you need to create link to the
module in your local node_modules directory. From the root of your project run :

```
ln -s /usr/local/lib/node_modules/motors/ node_modules/motors
```

Then just include it like a regular module like `var motors = require('motors');`.

#### motors.wheelsGap() ####
Get the programmed distance between the coding wheels in mm.

#### motors.wheelsGap(dist) ####
Set the distance between the coding wheels in mm.

#### motors.ticksPerMeter() ####
Get the programmed number of coding wheel ticks when robot 1 meter in a straight line.

#### motors.ticksPerMeter(ticks) ####
Set the number of coding wheel ticks when robot 1 meter in a straight line.

### motors.angular ###

#### motors.angular.acceleration() ####
Get robot maximum angular acceleration in mm/s^2.

#### motors.angular.acceleration(acceleration) ####
Set robot maximum angular acceleration in mm/s^2.

#### motors.angular.cruiseSpeed() ####
Get robot angular cruise speed in mm/s.

#### motors.angular.cruiseSpeed(speed) ####
Set robot angular cruise speed in mm/s.

#### motors.angular.p() ####
Get the robot angular PID P coefficient.

#### motors.angular.p(coeff) ####
Set the robot angular PID P coefficient.

#### motors.angular.i() ####
Get the robot angular PID I coefficient.

#### motors.angular.i(coeff) ####
Set the robot angular PID I coefficient.

#### motors.angular.d() ####
Get the robot angular PID D coefficient.

#### motors.angular.d(coeff) ####
Set the robot angular PID D coefficient.

### motors.linear ###

#### motors.linear.acceleration() ####
Get robot maximum linear acceleration in mm/s^2.

#### motors.linear.acceleration(acceleration) ####
Set robot maximum linear acceleration in mm/s^2.

#### motors.linear.cruiseSpeed() ####
Get robot linear cruise speed in mm/s.

#### motors.linear.cruiseSpeed(speed) ####
Set robot linear cruise speed in mm/s.

#### motors.linear.p() ####
Get the robot linear PID P coefficient.

#### motors.linear.p(coeff) ####
Set the robot linear PID P coefficient.

#### motors.linear.i() ####
Get the robot linear PID I coefficient.

#### motors.linear.i(coeff) ####
Set the robot linear PID I coefficient.

#### motors.linear.d() ####
Get the robot linear PID D coefficient.

#### motors.linear.d(coeff) ####
Set the robot linear PID D coefficient.


#### motors.writeFlash() ####
Write configuration in flash, it will be automatically reloaded at reset.

#### motors.x() ####
Get robot position x coordinate in mm.

#### motors.x(value) ####
Set robot position x coordinate in mm.

#### motors.y() ####
Get robot position y coordinate in mm.

#### motors.y(value) ####
Set robot position y coordinate in mm.

#### motors.heading() ####
Get robot heading, from 0 to 360 counterclockwise. When heading is 0, moving
forward increases y coordinate (x stays constant).

#### motors.heading(value) ####
Set robot heading, from 0 to 360 counterclockwise. When heading is 0, moving
forward increases y coordinate (x stays constant).

#### motors.distance() ####
Returns distance traveled in mm.

#### motors.goalHeading(heading) ####
Move robot to specified heading from 0 to 360 counterclockwise (low level).

#### motors.goalDistance(distance) ####
Move robot to a given distance in mm (low level).

#### motors.stop() ####
Stop the robot as soon as possible interrupting a move. Useful to avoid a
collision with another robot.

#### motors.resume() ####
Resume move interrupted by motors.stop().

#### motors.position(x, y) ####
Set robot position, x and y in mm.

#### motors.move(distance, callback) ####
Move forward or backward (if distance is negative) in a straight line of a given
distance in mm. callback is called when final position has been reached.

#### motors.turn(heading, callback) ####
Turn to given absolute heading from 0 to 360 counterclockwise. Callback is
called when final heading has been reached.

#### motor.moveTo(x, y, goalHeading, callback) ####
turn toward (x, y), go there then turn to goalAngle. Robot will try to minimize
rotation at the end of the movement so it will go forward or backward accordingly.
If no goalAngle is specified, robot will try to minimize start rotation and
go backward or forward accordingly. Function is non-blocking.
           x : x absolute coordinate in mm
           y : y absolute coordinate in mm
   goalAngle : final heading at goal location, or -1 if don't care
    callback : called when the move is over

### motors.path ###

#### motors.path.add(x, y, goalHeading, callback) ####
Queue a move to be executed by moveTo (see above for more info). If there's no
previously queued move, start the move directly.

#### motors.path.clear() ####
Removes all queued moves but does not stop current move. Callback of current
move won't be called.

#### motors.path.follow(path, callback) ####
Follow a path of points and call callback when last point and goal heading have
been reached.
Path should be an array of object like {x:..., y:..., angle:...} when x and y
in mm and angle in degrees from 0 to 360 counterclockwise.
