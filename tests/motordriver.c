#include <wiringPiI2C.h>
#include <libmotors/driver.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
  int x = getPosX();
  int y = getPosY();
  int heading = getHeading();

  printf("position [%d,%d], heading >%d°<\n", x, y, heading);
  return 0;
}
