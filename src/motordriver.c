#include "motorregs.h"
#include "i2c-functions.h"

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

// get/set current absolute position x (in mm)
void setPosX(int x) { I2Cwrite32(MOTOR_ADDR, X_POS, x); }
int  getPosX()      { return I2Cread32(MOTOR_ADDR, X_POS) };
// get/set current absolute position y (in mm)
void setPosY(int y) { I2Cwrite32(MOTOR_ADDR, Y_POS, y); }
int  getPosY()      { return I2Cread32(MOTOR_ADDR, Y_POS) };
// get/set current heading (in deg from 0 to 360 counterclockwise)
int getHeading()  { return I2Cread32(MOTOR_ADDR, HEADING); }
void setHeading(int heading) { I2Cwrite16(MOTOR_ADDR, HEADING, heading); }
// get distance robot has moved since last reset (in mm)
int getDistance() { return I2Cread32(MOTOR_ADDR, DIST); }

void setGoalDistance(int dist)   { I2Cwrite32(MOTOR_ADDR, GOAL_DIST, dist); }
void setGoalHeading(int heading) { I2Cwrite16(MOTOR_ADDR, GOAL_HEADING, heading); }

// stop moving as quick as possible
void emergencyStop() { I2Cwrite8(MOTOR_ADDR, EMERGENCY_STOP, 1); }
// resume movement interrupted by emergencyStop
void emergencyResume() { I2Cwrite8(MOTOR_ADDR, EMERGENCY_STOP, 0); }
