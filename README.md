# libmotors
A library providing control over robot's motion.

## Installation ##

This library is designed for Raspberry Pi with Raspbian.

* First, you need [wiringPi](http://wiringpi.com/download-and-install/) and
[librobotutils](https://github.com/TelecomParistoc/librobotutils).

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
