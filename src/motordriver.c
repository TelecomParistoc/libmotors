#include "motorregs.h"
#include <robotutils.h>

// read/write distance between coding wheels in mm
int  getWheelsGap()        { return I2Cread16(MOTOR_ADDR, WHEELS_GAP); }
void setWheelsGap(int gap) { I2Cwrite16(MOTOR_ADDR, WHEELS_GAP, gap); }

// read/write ticks per meter value
int  getTicksPerMeter()        { return I2Cread16(MOTOR_ADDR, TICKS_PER_M); }
void setTicksPerMeter(int val) { I2Cwrite16(MOTOR_ADDR, TICKS_PER_M, val); }

// read/write maximum linear (translating) acceleration
int  getLinearMaxAcceleration()         { return I2Cread16(MOTOR_ADDR, LIN_MAX_ACC); }
void setLinearMaxAcceleration(int acc)  { I2Cwrite16(MOTOR_ADDR, LIN_MAX_ACC, acc); }
// read/write maximum angular (rotating) acceleration
int  getAngularMaxAcceleration()        { return I2Cread16(MOTOR_ADDR, ANG_MAX_ACC); }
void setAngularMaxAcceleration(int acc) { I2Cwrite16(MOTOR_ADDR, ANG_MAX_ACC, acc); }

// read/write robot's linear (translating) speed when robot is not accelerating (in mm/s)
int  getLinearCruiseSpeed()           { return I2Cread16(MOTOR_ADDR, LIN_CRUISE_SPEED); }
void setLinearCruiseSpeed(int speed)  { I2Cwrite16(MOTOR_ADDR, LIN_CRUISE_SPEED, speed); }
// read/write robot's angular (rotating) speed when robot is not accelerating (in deg/s)
int  getAngularCruiseSpeed()          { return I2Cread16(MOTOR_ADDR, ANG_CRUISE_SPEED); }
void setAngularCruiseSpeed(int speed) { I2Cwrite16(MOTOR_ADDR, ANG_CRUISE_SPEED, speed); }

// read/write linear PID coefficients
int  getLinearP()          { return I2Cread16(MOTOR_ADDR, LINEAR_P); }
void setLinearP(int linP)  { I2Cwrite16(MOTOR_ADDR, LINEAR_P, linP); }
int  getLinearI()          { return I2Cread16(MOTOR_ADDR, LINEAR_I); }
void setLinearI(int linI)  { I2Cwrite16(MOTOR_ADDR, LINEAR_I, linI); }
int  getLinearD()          { return I2Cread16(MOTOR_ADDR, LINEAR_D); }
void setLinearD(int linD)  { I2Cwrite16(MOTOR_ADDR, LINEAR_D, linD); }
// read/write angular PID coefficients
int  getAngularP()         { return I2Cread16(MOTOR_ADDR, ANGULAR_P); }
void setAngularP(int angP) { I2Cwrite16(MOTOR_ADDR, ANGULAR_P, angP); }
int  getAngularI()         { return I2Cread16(MOTOR_ADDR, ANGULAR_I); }
void setAngularI(int angI) { I2Cwrite16(MOTOR_ADDR, ANGULAR_I, angI); }
int  getAngularD()         { return I2Cread16(MOTOR_ADDR, ANGULAR_D); }
void setAngularD(int angD) { I2Cwrite16(MOTOR_ADDR, ANGULAR_D, angD); }

// read/write motor configuration
int  getMotorLeftForwardSense()          { return I2Cread8(MOTOR_ADDR, MOTOR_LEFT_FORWARD_SENSE); }
void setMotorLeftForwardSense(int sense) { I2Cwrite16(MOTOR_ADDR, MOTOR_LEFT_FORWARD_SENSE, sense); }
int  getMotorRightForwardSense()          { return I2Cread8(MOTOR_ADDR, MOTOR_RIGHT_FORWARD_SENSE); }
void setMotorRightForwardSense(int sense) { I2Cwrite16(MOTOR_ADDR, MOTOR_RIGHT_FORWARD_SENSE, sense); }

// read/write coding wheels config
int  getCodingWheelLeftInitialTicks()          { return I2Cread32(MOTOR_ADDR, CODING_WHEEL_LEFT_INITIAL_TICKS); }
void setCodingWheelLeftInitialTicks(int ticks) { I2Cwrite32(MOTOR_ADDR, CODING_WHEEL_LEFT_INITIAL_TICKS, ticks); }
int  getCodingWheelRightInitialTicks()          { return I2Cread32(MOTOR_ADDR, CODING_WHEEL_RIGHT_INITIAL_TICKS); }
void setCodingWheelRightInitialTicks(int ticks) { I2Cwrite32(MOTOR_ADDR, CODING_WHEEL_RIGHT_INITIAL_TICKS, ticks); }

int  getCodingWheelLeftOrientation()                { return I2Cread8(MOTOR_ADDR, CODING_WHEEL_LEFT_ORIENTATION); }
void setCodingWheelLeftOrientation(int orientation) { I2Cwrite8(MOTOR_ADDR, CODING_WHEEL_LEFT_ORIENTATION, orientation); }
int  getCodingWheelRightOrientation()                { return I2Cread8(MOTOR_ADDR, CODING_WHEEL_RIGHT_ORIENTATION); }
void setCodingWheelRightOrientation(int orientation) { I2Cwrite8(MOTOR_ADDR, CODING_WHEEL_RIGHT_ORIENTATION, orientation); }


// write flash flash stored parameters in flash (waits a bit after issuing the
// command to allow the write to be done)
void writeMotorsFlash() {
	I2Cwrite8(MOTOR_ADDR, WRITE_FLASH, 1);
	waitFor(100);
}

// get/set current absolute position x (in mm)
void setPosX(float x) { I2CwriteFloat(MOTOR_ADDR, X_POS, x); }
float  getPosX()      { return I2CreadFloat(MOTOR_ADDR, X_POS); }
// get/set current absolute position y (in mm)
void setPosY(float y) { I2CwriteFloat(MOTOR_ADDR, Y_POS, y); }
float  getPosY()      { return I2CreadFloat(MOTOR_ADDR, Y_POS); }
// get/set current heading (in deg from 0 to 360 counterclockwise)
int getHeading()  { return I2Cread16(MOTOR_ADDR, HEADING); }
void setHeading(int heading) { I2Cwrite16(MOTOR_ADDR, HEADING, heading); }
// get distance robot has moved since last reset (in mm)
int getDistance() { return I2Cread32(MOTOR_ADDR, DIST); }

void setGoalDistance(int dist)   { I2Cwrite32(MOTOR_ADDR, GOAL_DIST, dist); }
void setGoalHeading(int heading) { I2Cwrite16(MOTOR_ADDR, GOAL_HEADING, heading); }

// make robot move until wall
void moveToWall()  { I2Cwrite8(MOTOR_ADDR, WALL_TO_RESET, 1); }
// get if the robot ended its move
int isMoveFinished() { I2CRead8(MOTOR_ADDR, END_OF_MOVE); }
// set direction when robot goes to wall
void setDirectionToWall(int forward) { I2Cwrite8(MOTOR_ADDR, DIRECTION_RESET, forward); }
// set orientation after robot reached the wall
void setOrientationAfterWall(int heading) { I2Cwrite16(MOTOR_ADDR, ORIENTATION_RESET, heading); }

// stop moving as quick as possible
void emergencyStop() { I2Cwrite8(MOTOR_ADDR, EMERGENCY_STOP, 1); }
// resume movement interrupted by emergencyStop
void emergencyResume() { I2Cwrite8(MOTOR_ADDR, EMERGENCY_STOP, 0); }
