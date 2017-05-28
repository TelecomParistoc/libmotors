#include <motors/driver.h>
#include <stdio.h>
#include <robotutils.h>

void mvdone2() {
	printf("start turning to 0deg\n");
	turn(0, NULL);
}

void turndone() {
	waitFor(1000);
	printf("turn completed\n");
	static int sign = 1;
	sign *= -1;
	turn(sign > 0 ? 90 : 270, turndone);
}

void mvdone() {
	printf("End of move\n");
	waitFor(1000);

	static int sign = -1;
	sign *= -1;
	move(sign * 600, mvdone);
	//printf("start turning to 90deg\n");
	//turn(90, turndone);
}

int main() {

	printf("Initialization : current pos = (0, 0), heading = 0\n");
	setPosition(3.14, 1.41);
	setHeading(0);

	//printf("start moving of 600mm\n");
	move(-600, mvdone);
	//turn(90, turndone);


	while(1) {
		printf("position [%.3f,%.3f], heading >%d°<\n", getPosX(), getPosY(), getHeading());
		printf("relatif : %d\n", getDistance());
		waitFor(1000);
	}
	return 0;
}
