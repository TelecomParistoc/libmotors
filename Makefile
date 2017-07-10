TARGET = libmotors.so
SRCS = motordriver.c motion.c queue.c
HEADERS = $(addprefix src/, ${SRCS:.c=.h}) src/driver.h
OBJECTS = $(addprefix build/,${SRCS:.c=.o})
TESTS = tests/simplemoves

CC=gcc
CFLAGS = -O2 -std=gnu99 -Wall -Werror -fpic
LDFLAGS= -shared -lwiringPi -lm -lpthread -lrobotutils
PREFIX = /usr/local
VPATH = build/

vpath %.c src/ tests/
vpath %.h src/

.PHONY: all build clean tests jsinstall


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
	rm -f $(TESTS)
	rm -f tests/*.o

jsinstall:
	mkdir -p $(DESTDIR)$(PREFIX)/lib/node_modules/motors
	cp -r JSbinding/* $(DESTDIR)$(PREFIX)/lib/node_modules/motors
	cd $(DESTDIR)$(PREFIX)/lib/node_modules/motors; npm install

install: build/$(TARGET) jsinstall
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include/motors
	cp build/$(TARGET) $(DESTDIR)$(PREFIX)/lib/
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/motors/
	chmod 0755 $(DESTDIR)$(PREFIX)/lib/$(TARGET)
	ldconfig
	ldconfig -p | grep motors

-include $(subst .c,.d,$(SRCS))
