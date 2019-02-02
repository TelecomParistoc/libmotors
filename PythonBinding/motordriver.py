import ctypes
from encapsulate_callback import encapsulate_callback

from motion import DIR_NONE, DIR_FORWARD, DIR_BACKWARD

lib_motors = ctypes.cdll.LoadLibrary(LIBNAME)

lib_motors.getWheelsGap.restype = ctypes.c_int
lib_motors.setWheelsGap.restype = None

lib_motors.getTicksPerMeter.restype = ctypes.c_int
lib_motors.setTicksPerMeter.restype = None

lib_motors.getLinearMaxAcceleration.restype = ctypes.c_int
lib_motors.setLinearMaxAcceleration.restype = None
lib_motors.getAngularMaxAcceleration.restype = ctypes.c_int
lib_motors.setAngularMaxAcceleration.restype = None

lib_motors.getLinearCruiseSpeed.restype = ctypes.c_int
lib_motors.setLinearCruiseSpeed.restype = None
lib_motors.getAngularCruiseSpeed.restype = ctypes.c_int
lib_motors.setAngularCruiseSpeed.restype = None

lib_motors.getLinearP.restype = ctypes.c_int
lib_motors.setLinearP.restype = None
lib_motors.getLinearI.restype = ctypes.c_int
lib_motors.setLinearI.restype = None
lib_motors.getLinearD.restype = ctypes.c_int
lib_motors.setLinearD.restype = None

lib_motors.getAngularP.restype = ctypes.c_int
lib_motors.setAngularP.restype = None
lib_motors.getAngularI.restype = ctypes.c_int
lib_motors.setAngularI.restype = None
lib_motors.getAngularD.restype = ctypes.c_int
lib_motors.setAngularD.restype = None

lib_motors.getLeftMotorCoeff.restype = ctypes.c_int
lib_motors.setLeftMotorCoeff.restype = None
lib_motors.getRightMotorCoeff.restype = ctypes.c_int
lib_motors.setRightMotorCoeff.restype = ctypes.c_int

lib_motors.getMotorLeftForwardSense.restype = ctypes.c_int
lib_motors.setMotorLeftForwardSense.restype = None
lib_motors.getMotorRightForwardSense.restype = ctypes.c_int
lib_motors.setMotorRightForwardSense.restype = None

lib_motors.getCodingWheelLeftInitialTicks.restype = ctypes.c_int
lib_motors.setCodingWheelLeftInitialTicks.restype = None
lib_motors.getCodingWheelRightInitialTicks.restype = ctypes.c_int
lib_motors.setCodingWheelRightInitialTicks.restype = None

lib_motors.getCodingWheelLeftOrientation.restype = ctypes.c_int
lib_motors.getCodingWheelLeftOrientation.restype = None
lib_motors.getCodingWheelRightOrientation.restype = ctypes.c_int
lib_motors.getCodingWheelRightOrientation.restype = None

lib_motors.writeMotorsFlash.restype = None

lib_motors.getPosX.restype = ctypes.c_int
lib_motors.setPosX.restype = None
lib_motors.getPosY.restype = ctypes.c_int
lib_motors.setPosY.restype = None

lib_motors.getHeading.restype = ctypes.c_int
lib_motors.setHeading.restype = None

lib_motors.getDistance.restype = ctypes.c_int
lib_motors.setGoalDistance.restype = None
lib_motors.setGoalHeading.restype =  None

lib_motors.emergencyStop.restype = None
lib_motors.emergencyResume.restype = None

lib_motors.moveToWall.restype = None
lib_motors.setDirectionToWall.restype = None
lib_motors.setOrientationAfterWall.restype = None

# Checks if x is a number (int or float)
def check_number(x):
    assert(isinstance(x, int) or isinstance(x, float))


# Distance between the coding wheels in mm
def get_wheels_gap():
    return lib_motors.getWheelsGap()

def set_wheels_gap(gap):
    check_number(gap)
    lib_motors.setWheelsGap(ctypes.c_int(gap))


# Ticks per meter value
def get_ticks_per_meter():
    return lib_motors.getTicksPerMeter()

def set_ticks_per_meter(val):
    check_number(val)
    lib_motors.set_ticks_per_meter(ctypes.c_int(val))


# Maximum translating acceleration (in mm.s^-2)
def get_linear_max_acceleration():
    return lib_motors.getLinearMaxAcceleration()

def set_linear_max_acceleration(acc):
    check_number(acc)
    lib_motors.setLinearMaxAcceleration(ctypes.c_int(acc))


# Maximum rotating acceleration (in deg.s^-2)
def get_angular_max_acceleration():
    return lib_motors.getAngularMaxAcceleration()

def set_angular_max_acceleration(acc):
    check_number(acc)
    return lib_motors.setAngularMaxAcceleration(ctypes.c_int(acc))


# Translating speed when the robot is not accelerating (in mm/s)
def get_linear_cruise_speed():
    return lib_motors.getLinearCruiseSpeed()

def set_linear_cruise_speed(speed):
    check_number(speed)
    lib_motors.setLinearCruiseSpeed(ctypes.c_int(speed))


# Rotating speed when the robot is not accelerating (in deg/s)
def get_angular_cruise_speed():
    return lib_motors.getAngularCruiseSpeed()

def set_angular_cruise_speed(speed):
    check_number(speed)
    lib_motors.setAngularCruiseSpeed(ctypes.c_int(speed))


# read/write linear PID coefficients
def get_linear_P():
    return lib_motors.getLinearP()

def set_linear_P(linP):
    check_number(linP)
    lib_motors.setLinearP(ctypes.c_int(linP))

def get_linear_I():
    return lib_motors.getLinearI()

def set_linear_I(linI):
    check_number(linI)
    lib_motors.setLinearI(ctypes.c_int(linI))

def get_linear_D():
    return lib_motors.getLinearD()

def set_linear_D(linD):
    check_number(linD)
    lib_motors.setLinearD(ctypes.c_int(linD))


# read/write angular PID coefficients
def get_angular_P():
    return lib_motors.getAngularP()

def set_angular_P(angP):
    check_number(angP)
    lib_motors.setAngularP(ctypes.c_int(angP))

def get_angular_I():
    return lib_motors.getAngularI()

def set_angular_I(angI):
    check_number(angI)
    lib_motors.setAngularI(ctypes.c_int(angI))

def get_angular_D():
    return lib_motors.getAngularD()

def set_angular_D(angD):
    check_number(angD)
    lib_motors.setAngularD(ctypes.c_int(angD))

#motor calibration
def get_left_motor_coeff():
    return lib_motors.getLeftMotorCoeff()

def set_left_motor_coeff(left_coeff):
    check_number(left_coeff)
    if left_coeff < 500 or left_coeff > 1500:
        print "[WARNING] left_motor_coeff is in per 1000, the value ", left_coeff, "is odd..."
    lib_motors.setLeftMotorCoeff(ctypes.c_int(left_coeff))
    lib_motors.writeMotorsFlash()

def get_right_motor_coeff():
    return lib_motors.getRightMotorCoeff()

def set_right_motor_coeff(right_coeff):
    check_number(right_coeff)
    if right_coeff < 500 or right_coeff > 1500:
        print "[WARNING] right_motor_coeff is in per 1000, the value ", right_coeff, "is odd..."
    lib_motors.setRightMotorCoeff(ctypes.c_int(right_coeff))
    lib_motors.writeMotorsFlash()

# read/write motor configuration
def get_motor_left_forward_sense():
    return lib_motors.getMotorLeftForwardSense()

def set_motor_left_forward_sense(sense):
    check_number(sense)
    lib_motors.setMotorLeftForwardSense(ctypes.c_int(sense))

def get_motor_right_forward_sense():
    return lib_motors.getMotorRightForwardSense()

def set_motor_right_forward_sense(sense):
    check_number(sense)
    lib_motors.setMotorRightForwardSense(ctypes.c_int(sense))

# read/white coding wheel configuration
def get_coding_wheel_left_initial_ticks():
    return lib_motors.getCodingWheelLeftInitialTicks()

def set_coding_wheel_left_initial_ticks(ticks):
    check_number(ticks)
    lib_motors.setCodingWheelLeftInitialTicks(ctypes.c_int(ticks))

def get_coding_wheel_right_initial_ticks():
    return lib_motors.getCodingWheelRightInitialTicks()

def set_coding_wheel_right_initial_ticks(ticks):
    check_number(ticks)
    lib_motors.setCodingWheelRightInitialTicks(ctypes.c_int(ticks))

def get_coding_wheel_left_orientation():
    return lib_motors.getCodingWheelLeftOrientation()

def set_coding_wheel_left_orientation(orientation):
    check_number(orientation)
    lib_motors.setCodingWheelLeftOrientation(ctypes.c_int(orientation))

def get_coding_wheel_right_orientation():
    return lib_motors.getCodingWheelRightOrientation()

def set_coding_wheel_right_orientation(orientation):
    check_number(orientation)
    lib_motors.setCodingWheelRightOrientation(ctypes.c_int(orientation))

# Write flash stored parameters in flash (waits a bit after issuing the
# command to allow the write to be done)
def write_motors_flash():
    lib_motors.writeMotorsFlash()

# get/set current absolute position x (in mm)
def get_pos_X():
    return lib_motors.getPosX()

def set_pos_X(x):
    check_number(x)
    lib_motors.setPosX(ctypes.c_int(x))

# get/set current absolute position x (in mm)
def get_pos_Y():
    return lib_motors.getPosY()

def set_pos_Y(y):
    check_number(y)
    lib_motors.setPosY(ctypes.c_int(y))

# get/set current heading (in deg from 0 to 360 counterclockwise)
def get_heading():
    return lib_motors.getHeading()

def set_heading(heading):
    check_number(heading)
    lib_motors.setHeading(ctypes.c_int(heading))

# Get the distance traveled by the robot since the last reset (in mm)
def get_distance():
    return lib_motors.getDistance()

# Make the robot move to a given distance (in mm)
def set_goal_distance(dist):
    check_number(dist)
    lib_motors.setGoalDistance(ctypes.c_int(dist))

# Make the robot rotate to the given heading (in deg from 0 to 360 conterclockwise)
def set_goal_heading(heading):
    check_number(heading)
    lib_motors.setGoalHeading(ctypes.c_int(heading))

# Stop moving as quickly as possible
def emergency_stop():
    lib_motors.emergencyStop()

# Resume the movement interrupted by emergency_stop
def emergency_resume():
    lib_motors.emergencyResume()

def move_to_wall():
    #make sure set_direction_to_wall have been called before!
    lib_motors.moveToWall()

def set_direction_to_wall(direction):
    if direction != DIR_FORWARD and direction != DIR_BACKWARD:
        raise ValueError("set_direction_to_wall: direction must be DIR_FORWARD or DIR_BACKWARD")
    lib_motors.setDirectionToWall(ctypes.c_int(direction))

def set_orientation_after_wall(orientation):
    check_number(orientation)
    if orientation < 0 or orientation >= 360:
        raise ValueError("orientation must be in range [0, 360[")
    lib_motors.setOrientationAfterWall(ctypes.c_int(orientation))
