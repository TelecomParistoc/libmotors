#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* read/write distance between coding wheels in mm */
int  getWheelsGap();
void setWheelsGap(int gap);

/* read/write ticks per meter value */
int  getTicksPerMeter();
void setTicksPerMeter(int val);

/* read/write maximum linear (translating) acceleration (in mm/s^2) */
int  getLinearMaxAcceleration();
void setLinearMaxAcceleration(int acc);
/* read/write maximum angular (rotating) acceleration (in deg/s^2) */
int  getAngularMaxAcceleration();
void setAngularMaxAcceleration(int acc);

/* read/write robot's linear (translating) speed when robot is not accelerating (in mm/s) */
int  getLinearCruiseSpeed();
void setLinearCruiseSpeed(int speed);
/* read/write robot's angular (rotating) speed when robot is not accelerating (in deg/s) */
int  getAngularCruiseSpeed();
void setAngularCruiseSpeed(int speed);

/* read/write linear PID coefficients */
int  getLinearP();
void setLinearP(int linP);
int  getLinearI();
void setLinearI(int linI);
int  getLinearD();
void setLinearD(int linD);
/* read/write angular PID coefficients */
int  getAngularP();
void setAngularP(int angP);
int  getAngularI();
void setAngularI(int angI);
int  getAngularD();
void setAngularD(int angD);

/* motor calibration */
int   getLeftMotorCoeff();
void  setLeftMotorCoeff(int left_coeff);
int   getRightMotorCoeff();
void  setRightMotorCoeff(int right_coeff);

/* read/write motor configuration */
int  getMotorLeftForwardSense();
void setMotorLeftForwardSense(int sense);
int  getMotorRightForwardSense();
void setMotorRightForwardSense(int sense);

/* read/write coding wheels config */
int  getCodingWheelLeftInitialTicks();
void setCodingWheelLeftInitialTicks(int ticks);
int  getCodingWheelRightInitialTicks();
void setCodingWheelRightInitialTicks(int ticks);

int  getCodingWheelLeftOrientation();
void setCodingWheelLeftOrientation(int orientation);
int  getCodingWheelRightOrientation();
void setCodingWheelRightOrientation(int orientation);


/* write flash stored parameters in flash (waits a bit after issuing the
 * command to allow the write to be done) */
void writeMotorsFlash();

/* get/set current absolute position x (in mm) */
int  getPosX();
void setPosX(int x);
/* get/set current absolute position y (in mm) */
int  getPosY();
void setPosY(int y);
/* get/set current heading (in deg from 0 to 360 counterclockwise) */
int  getHeading();
void setHeading(int heading);
/* get distance robot has moved since last reset (in mm) */
int  getDistance();

/* make robot move to a given distance (in mm) */
void setGoalDistance(int dist);
/* make the robot rotate to the given heading (in deg from 0 to 360 counterclockwise) */
void setGoalHeading(int heading);

/* make robot move until wall */
void moveToWall();
/* get if the robot ended its move */
int isMoveFinished();
/* set direction when robot goes to wall */
void setDirectionToWall(int forward);
/* set orientation after robot reached the wall */
void setOrientationAfterWall(int heading);

/* stop moving as quick as possible */
void emergencyStop();
/* resume movement interrupted by emergencyStop */
void emergencyResume();

#ifdef __cplusplus
}
#endif

#endif
