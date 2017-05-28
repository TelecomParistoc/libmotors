#include <motors/driver.h>
#include <stdio.h>
#include <stdlib.h>
#include <robotutils.h>

char running = 1;

void end(){
  printf("end reached...\n");
  running = 0;
}

int main(int argc, char* argv[]) {
  setPosition(0, 0);
	setHeading(0);
	moveTo(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10), 0, NULL);

  while (running) {
		printf("position [%.3f,%.3f], heading >%d°<\n", getPosX(), getPosY(), getHeading());
		waitFor(1000);
	}
	return 0;
}
