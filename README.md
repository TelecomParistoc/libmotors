# libmotors
A library providing control over robot's motion.

## Installation ##

This library is designed for Raspberry Pi with Raspbian.

* First, you need [wiringPi](http://wiringpi.com/download-and-install/) and
[librobotutils](https://github.com/TelecomParistoc/librobotutils).

* You also need to install libxml2-dev

* Once dependencies are installed, get back the sources :
`git clone git@github.com:TelecomParistoc/libmotors.git`

* cd to the root of the repository and enter `make`

* finally enter `sudo make install`

## Usage ##

Don't forget to compile (actually, link) your C/C++ app with `-lmotors` option.
You can include all the headers you need with :
```c
#include <motors/driver.h>
```

### Low level functions ###

Low level functions allow to configure and send commands to the motor controller
through the I2C bus, that is :

* configure the controller parameters (N.B : to make the configuration permanent
	call `writeMotorsFlash()`)
* get and set robot position and heading.
* set position control goals (without callbacks)

For more info, see [motordriver.h](https://github.com/TelecomParistoc/libmotors/blob/master/src/motordriver.h).

### High level functions ###

High level functions allows to easily and asynchronously control robot moves
with different level of abstraction :

* move and turn allow to asynchronously start relative motions
* moveTo allows to move robot to absolute coordinates
* addPointInPath allows program sequence of absolute moves

For more info, see [motion.h](https://github.com/TelecomParistoc/libmotors/blob/master/src/motion.h).

## Tests ##

Several simple programs are provided to check that the library is working properly.

To run the tests, run `make tests` from the root of the repository, and run
some of the programs created in tests/.

## Bindings ##

Bindings are provided to use libmotors with other languages than C/C++.

### Javascript ###

Most of the reasonable programmers use and love Javascript/Coffeescript.
That's why a simple JS binding is provided, allowing to call motor driver functions
from javascript. Check [JSbinding/README.md](https://github.com/TelecomParistoc/libmotors/blob/master/JSbinding/README.md)
for more info.
