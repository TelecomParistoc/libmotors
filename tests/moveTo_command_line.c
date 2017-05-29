#include <motors/driver.h>
#include <stdio.h>
#include <stdlib.h>
#include <robotutils.h>

volatile char running = 1;

void end(){
  printf("end reached...\n");
  running = 0;
}

int main(int argc, char* argv[]) {
  setPosition(0, 0);
	setHeading(0);
  waitFor(200);
	moveTo(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10), 0, end);

  while (running) {
		printf("position [%.3f,%.3f], heading >%d°<, distance = %d\n", getPosX(), getPosY(), getHeading(), getDistance());
		waitFor(1000);
	}
	return 0;
}
