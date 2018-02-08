#include <motors/driver.h>
#include <motors/motion.h>
#include <robotutils.h>
#include <stdio.h>


void mvdone() {
	printf("End of move\n");
	waitFor(1000);
}

int main() {

	printf("Initialization : current pos = (0, 0), heading = 0\n");
	setPosition(0, 0);
	setHeading(0);

	//printf("start moving until wall\n");
	moveUntilWall(300, mvdone);

	while(1) {
		printf("position [%d,%d], heading >%d°<\n", getPosX(), getPosY(), getHeading());
		printf("relatif : %d\n", getDistance());
		waitFor(1000);
	}
	return 0;
}
