import ctypes
from encapsulate_callback import encapsulate_callback

lib_motors = ctypes.cdll.LoadLibrary(LIBNAME)

lib_motors.move.restype = None
lib_motors.turn.restype = None
lib_motors.getDirection.restype = ctypes.c_int
lib_motors.setPosition.restype = None
lib_motors.moveTo.restype = None
lib_motors.addPointInPath.restype = None

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
    return lib_motors.getLinearMaxAcceleration

def set_linear_max_acceleration(acc):
    check_number(acc)
    lib_motors.setLinearMaxAcceleration(ctypes.c_int(acc))


# Maximum rotating acceleration (in deg.s^-2)
def get_angular_max_acceleration():
    return lib_motors.getAngularMaxAcceleration();

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
    lib_motors.set_linear_P(ctypes.c_int(linP))

def get_linear_I():
    return lib_motors.getLinearP()

def set_linear_I(linI):
    check_number(linI)
    lib_motors.setLinearI(ctypes.c_int(linI))

def get_linear_D():
    return lib_motors.getLinearP()

def set_linear_D(linP):
    check_number(linP)
    lib_motors.setLinearP(ctypes.c_int(linP))
