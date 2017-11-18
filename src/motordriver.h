#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

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
float  getPosX();
void setPosX(float x);
/* get/set current absolute position y (in mm) */
float  getPosY();
void setPosY(float y);
/* get/set current heading (in deg from 0 to 360 counterclockwise) */
int  getHeading();
void setHeading(int heading);
/* get distance robot has moved since last reset (in mm) */
int  getDistance();

/* make robot move to a given distance (in mm) */
void setGoalDistance(int dist);
/* make the robot rotate to the given heading (in deg from 0 to 360 counterclockwise) */
void setGoalHeading(int heading);

/* stop moving as quick as possible */
void emergencyStop();
/* resume movement interrupted by emergencyStop */
void emergencyResume();

#endif
