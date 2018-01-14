#include "motorregs.h"
#include <robotutils.h>

// read/write distance between coding wheels in mm
int  getWheelsGap()        { return I2Cread16(DEVICE_ADDR, SETTINGS_WHEELS_GAP_ADDR); }
void setWheelsGap(int gap) { I2Cwrite16(DEVICE_ADDR, SETTINGS_WHEELS_GAP_ADDR, gap); }

// read/write ticks per meter value
int  getTicksPerMeter()        { return I2Cread16(DEVICE_ADDR, SETTINGS_TICKS_PER_M_ADDR); }
void setTicksPerMeter(int val) { I2Cwrite16(DEVICE_ADDR, SETTINGS_TICKS_PER_M_ADDR, val); }

// read/write maximum linear (translating) acceleration
int  getLinearMaxAcceleration()         { return I2Cread16(DEVICE_ADDR, SETTINGS_MAX_LINEAR_ACCELERATION_ADDR); }
void setLinearMaxAcceleration(int acc)  { I2Cwrite16(DEVICE_ADDR, SETTINGS_MAX_LINEAR_ACCELERATION_ADDR, acc); }
// read/write maximum angular (rotating) acceleration
int  getAngularMaxAcceleration()        { return I2Cread16(DEVICE_ADDR, SETTINGS_MAX_ANGULAR_ACCELERATION_ADDR); }
void setAngularMaxAcceleration(int acc) { I2Cwrite16(DEVICE_ADDR, SETTINGS_MAX_ANGULAR_ACCELERATION_ADDR, acc); }

// read/write robot's linear (translating) speed when robot is not accelerating (in mm/s)
int  getLinearCruiseSpeed()           { return I2Cread16(DEVICE_ADDR, SETTINGS_CRUISE_LINEAR_SPEED_ADDR); }
void setLinearCruiseSpeed(int speed)  { I2Cwrite16(DEVICE_ADDR, SETTINGS_CRUISE_LINEAR_SPEED_ADDR, speed); }
// read/write robot's angular (rotating) speed when robot is not accelerating (in deg/s)
int  getAngularCruiseSpeed()          { return I2Cread16(DEVICE_ADDR, SETTINGS_CRUISE_ANGULAR_SPEED_ADDR); }
void setAngularCruiseSpeed(int speed) { I2Cwrite16(DEVICE_ADDR, SETTINGS_CRUISE_ANGULAR_SPEED_ADDR, speed); }

// read/write linear PID coefficients
int  getLinearP()          { return I2Cread16(DEVICE_ADDR, SETTINGS_LINEAR_COEFF_P_ADDR); }
void setLinearP(int linP)  { I2Cwrite16(DEVICE_ADDR, SETTINGS_LINEAR_COEFF_P_ADDR, linP); }
int  getLinearI()          { return I2Cread16(DEVICE_ADDR, SETTINGS_LINEAR_COEFF_I_ADDR); }
void setLinearI(int linI)  { I2Cwrite16(DEVICE_ADDR, SETTINGS_LINEAR_COEFF_I_ADDR, linI); }
int  getLinearD()          { return I2Cread16(DEVICE_ADDR, SETTINGS_LINEAR_COEFF_D_ADDR); }
void setLinearD(int linD)  { I2Cwrite16(DEVICE_ADDR, SETTINGS_LINEAR_COEFF_D_ADDR, linD); }
// read/write angular PID coefficients
int  getAngularP()         { return I2Cread16(DEVICE_ADDR, SETTINGS_ANGULAR_COEFF_P_ADDR); }
void setAngularP(int angP) { I2Cwrite16(DEVICE_ADDR, SETTINGS_ANGULAR_COEFF_P_ADDR, angP); }
int  getAngularI()         { return I2Cread16(DEVICE_ADDR, SETTINGS_ANGULAR_COEFF_I_ADDR); }
void setAngularI(int angI) { I2Cwrite16(DEVICE_ADDR, SETTINGS_ANGULAR_COEFF_I_ADDR, angI); }
int  getAngularD()         { return I2Cread16(DEVICE_ADDR, SETTINGS_ANGULAR_COEFF_D_ADDR); }
void setAngularD(int angD) { I2Cwrite16(DEVICE_ADDR, SETTINGS_ANGULAR_COEFF_D_ADDR, angD); }

// read/write motor configuration
int  getMotorLeftForwardSense()          { return I2Cread8(DEVICE_ADDR, SETTINGS_MOTOR_LEFT_FORWARD_SENSE_ADDR); }
void setMotorLeftForwardSense(int sense) { I2Cwrite16(DEVICE_ADDR, SETTINGS_MOTOR_LEFT_FORWARD_SENSE_ADDR, sense); }
int  getMotorRightForwardSense()          { return I2Cread8(DEVICE_ADDR, SETTINGS_MOTOR_RIGHT_FORWARD_SENSE_ADDR); }
void setMotorRightForwardSense(int sense) { I2Cwrite16(DEVICE_ADDR, SETTINGS_MOTOR_RIGHT_FORWARD_SENSE_ADDR, sense); }

// read/write coding wheels config
int  getCodingWheelLeftInitialTicks()          { return I2Cread32(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_INITIAL_LEFT_TICKS_LOW_ADDR); }
void setCodingWheelLeftInitialTicks(int ticks) { I2Cwrite32(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_INITIAL_LEFT_TICKS_LOW_ADDR, ticks); }
int  getCodingWheelRightInitialTicks()          { return I2Cread32(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_INITIAL_RIGHT_TICKS_LOW_ADDR); }
void setCodingWheelRightInitialTicks(int ticks) { I2Cwrite32(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_INITIAL_RIGHT_TICKS_LOW_ADDR, ticks); }

int  getCodingWheelLeftOrientation()                { return I2Cread8(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_LEFT_WHEEL_ORIENTATION_ADDR); }
void setCodingWheelLeftOrientation(int orientation) { I2Cwrite8(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_LEFT_WHEEL_ORIENTATION_ADDR, orientation); }
int  getCodingWheelRightOrientation()                { return I2Cread8(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_RIGHT_WHEEL_ORIENTATION_ADDR); }
void setCodingWheelRightOrientation(int orientation) { I2Cwrite8(DEVICE_ADDR, SETTINGS_CODING_WHEELS_CONFIG_RIGHT_WHEEL_ORIENTATION_ADDR, orientation); }


// write flash flash stored parameters in flash (waits a bit after issuing the
// command to allow the write to be done)
void writeMotorsFlash() {
	I2Cwrite8(DEVICE_ADDR, STORE_DATA_IN_FLASH_ADDR, 1);
	waitFor(100);
}

// get/set current absolute position x (in mm)
void setPosX(int x) { I2Cwrite16(DEVICE_ADDR, CUR_POS_X_ADDR, x); }
int getPosX()      { return I2Cread16(DEVICE_ADDR, CUR_POS_X_ADDR); }
// get/set current absolute position y (in mm)
void setPosY(int y) { I2Cwrite16(DEVICE_ADDR, CUR_POS_Y_ADDR, y); }
int getPosY()      { return I2Cread16(DEVICE_ADDR, CUR_POS_Y_ADDR); }
// get/set current heading (in deg from 0 to 360 counterclockwise)
int getHeading()  { return I2Cread16(DEVICE_ADDR, CUR_HEADING_ADDR); }
void setHeading(int heading) { I2Cwrite16(DEVICE_ADDR, CUR_HEADING_ADDR, heading); }
// get distance robot has moved since last reset (in mm)
int getDistance() { return I2Cread32(DEVICE_ADDR, CURRENT_DISTANCE_LOW_ADDR); }

void setGoalDistance(int dist)   { I2Cwrite32(DEVICE_ADDR, GOAL_MEAN_DIST_LOW_ADDR, dist); }
void setGoalHeading(int heading) { I2Cwrite16(DEVICE_ADDR, GOAL_HEADING_ADDR, heading); }

// make robot move until wall
void moveToWall()  { I2Cwrite8(DEVICE_ADDR, RESET_ORIENTATION_ADDR, 1); }
// get if the robot ended its move
int isMoveFinished() {return I2Cread8(DEVICE_ADDR, TRANSLATION_ENDED_ADDR); }
// set direction when robot goes to wall
void setDirectionToWall(int forward) { I2Cwrite8(DEVICE_ADDR, RESET_ORIENTATION_DIRECTION_ADDR, forward); }
// set orientation after robot reached the wall
void setOrientationAfterWall(int heading) { I2Cwrite16(DEVICE_ADDR, RESET_ORIENTATION_ORIENTATION_ADDR, heading); }

// stop moving as quick as possible
void emergencyStop() { I2Cwrite8(DEVICE_ADDR, MASTER_STOP_ADDR, 1); }
// resume movement interrupted by emergencyStop
void emergencyResume() { I2Cwrite8(DEVICE_ADDR, MASTER_STOP_ADDR, 0); }
