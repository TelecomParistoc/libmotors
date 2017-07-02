#include <motors/driver.h>
#include <stdio.h>
#include <robotutils.h>

void mvdone2() {
	printf("start turning to 0deg\n");
	turn(0, NULL);
}

void turndone() {
	waitFor(1000);
	printf("start moving of -100mm\n");
	move(-100, mvdone2);
}

void mvdone() {
	waitFor(1000);
	printf("start turning to 90deg\n");
	turn(90, turndone);
}

int main() {
	printf("start moving of 100mm\n");
	move(100, mvdone);
	setPosition(0, 0);
	setHeading(0);

	while(1) {
		printf("position [%d,%d], heading >%d°<\n", getPosX(), getPosY(), getHeading());
		waitFor(100);
	}
	return 0;
}
