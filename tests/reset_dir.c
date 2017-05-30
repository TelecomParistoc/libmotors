#include <motors/driver.h>
#include <stdio.h>
#include <robotutils.h>

int main() {

	printf("lin P %d, I %d, D %d\n", getLinearP(), getLinearI(), getLinearD());
	printf("isMoveFinished %d\n", isMoveFinished());
	setDirectionToWall(1);
	setOrientationAfterWall(25);
	moveToWall();

	while (!isMoveFinished()) {
		printf("not\n");
		waitFor(100);
	}
	printf("yes\n");
	printf("isMoveFinished %d\n", isMoveFinished());
	return 0;
}
