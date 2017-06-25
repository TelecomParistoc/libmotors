/* This file define motor controller I2C register addresses
 * All registers are 16 bits unless specified */

#ifndef MOTORREGS_H
#define MOTORREGS_H

// I2C address of the motor controller
#define MOTOR_ADDR 0x12

// ################  FLASH REGISTERS  ################

// distance between the wheel in mm
#define WHEELS_GAP        0x00
// coding wheels number of ticks per meter
#define TICKS_PER_M       0x02
// ??
#define ANG_TRUST_THRES   0x04

// Maximum linear acceleration in mm/s^2
#define LIN_MAX_ACC       0x06
// Maximum angular acceleration in degrees/s^2
#define ANG_MAX_ACC       0x08
// Cruise speed linear in m/s
#define LIN_CRUISE_SPEED  0x0A
// Cruise speed angular in degrees/s
#define ANG_CRUISE_SPEED  0x0C

// Linear p coefficient
#define LINEAR_P          0x0E
// Linear i coefficient
#define LINEAR_I          0x10
// Linear d coefficient
#define LINEAR_D          0x12

// Angular p coefficient
#define ANGULAR_P         0x14
// Angular i coefficient
#define ANGULAR_I         0x16
// Angular d coefficient
#define ANGULAR_D         0x18


// ################  RAM REGISTERS  ################

// write PID coefficients in flash (8 bits)
#define WRITE_FLASH       0x20

// Current x absolute position in mm (32 bits)
#define X_POS             0x80
// Current y absolute position in mm (32 bits)
#define Y_POS             0x84
// Current right wheel distance in ?? (32 bits)
#define R_WHEEL           0x88
// Current left wheel distance in ?? (32 bits)
#define L_WHEEL           0x8C

// Current heading in degrees
#define HEADING           0x90
// current distance in mm (32 bits)
#define DIST              0x92

// Goal distance in mm (32 bits)
#define GOAL_DIST         0xA0
// Goal heading in degrees
#define GOAL_HEADING      0xA4

// Heading distance sync reference
#define HEADING_DIST_SYNC_REF 0xA6
// stop robot quickly (8 bits)
#define EMERGENCY_STOP    0xA8

#endif
