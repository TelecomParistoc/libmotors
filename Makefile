TARGET = libmotors.so
SRCS = motordriver.c motion.c queue.c
HEADERS = $(addprefix src/, ${SRCS:.c=.h}) src/driver.h
OBJECTS = $(addprefix build/,${SRCS:.c=.o})
TESTS = tests/simplemoves tests/absolute tests/galette tests/moveTo_command_line tests/reset_dir tests/move_to_wall

CC=gcc
CFLAGS = -O2 -std=gnu99 -Wall -Werror -fpic
LDFLAGS= -shared -lwiringPi -lm -lpthread -lrobotutils
PREFIX = /usr/local
VPATH = build/

vpath %.c src/ tests/
vpath %.h src/

.PHONY: all build clean tests jsinstall motorconf


all: build build/$(TARGET)

build:
	@mkdir -p build
build/%.o: %.c build/%.d
	@echo "$<"
	@$(CC) -c -o $@ $< $(CFLAGS)
build/%.d : %.c
	@$(CC) $(CFLAGS) -MM -MF $@ -MP $<

build/$(TARGET): $(OBJECTS)
	@echo "\nLinking target $@"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

tests: LDFLAGS=-lmotors -lrobotutils
tests: $(TESTS)

tests/%: tests/%.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -f build/*.o build/*.so build/*.d
	rm -f $(TESTS) tests/*.o

jsinstall:
	mkdir -p $(DESTDIR)$(PREFIX)/lib/node_modules/motors
	cp -r JSbinding/* $(DESTDIR)$(PREFIX)/lib/node_modules/motors
	cd $(DESTDIR)$(PREFIX)/lib/node_modules/motors; npm install

motorconf:
	mkdir -p $(DESTDIR)$(PREFIX)/lib/node_modules/motorconf
	cp -r motorconf/* $(DESTDIR)$(PREFIX)/lib/node_modules/motorconf
	cd $(DESTDIR)$(PREFIX)/lib/node_modules/motorconf; npm install
	rm -f $(DESTDIR)$(PREFIX)/lib/node_modules/motorconf/node_modules/motors
	ln -s $(DESTDIR)$(PREFIX)/lib/node_modules/motors $(DESTDIR)$(PREFIX)/lib/node_modules/motorconf/node_modules/motors
	cp motorconf/motorconf $(DESTDIR)$(PREFIX)/bin/
	chmod a+x $(DESTDIR)$(PREFIX)/bin/motorconf

install: build/$(TARGET) jsinstall motorconf
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include/motors
	cp build/$(TARGET) $(DESTDIR)$(PREFIX)/lib/
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/motors/
	chmod 0755 $(DESTDIR)$(PREFIX)/lib/$(TARGET)
	ldconfig
	ldconfig -p | grep motors


bigConfig:
	motorconf write wheelsgap 			150
	motorconf write tickspermeter 	5100
	motorconf write linacc 					10
	motorconf write angacc 					50
	motorconf write linspeed				30
	motorconf write angspeed 				45
	motorconf write linp						800
	motorconf write lini 						0
	motorconf write lind 						0
	motorconf write angp						100
	motorconf write angi 						0
	motorconf write angd 						0
	motorconf write ldir 						1
	motorconf write lwheeldir 			1
	motorconf write rdir 						1
	motorconf write rwheeldir 			0

smallConfig:
	motorconf write wheelsgap 			95
	motorconf write tickspermeter 	5100
	motorconf write linacc 					10
	motorconf write angacc 					50
	motorconf write linspeed				30
	motorconf write angspeed 				45
	motorconf write linp						800
	motorconf write lini 						0
	motorconf write lind 						0
	motorconf write angp						100
	motorconf write angi 						0
	motorconf write angd 						0
	motorconf write ldir 						0
	motorconf write lwheeldir 			0
	motorconf write rdir 						1
	motorconf write rwheeldir 			1






-include $(subst .c,.d,$(SRCS))
