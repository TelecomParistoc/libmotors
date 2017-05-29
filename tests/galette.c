#include <motors/driver.h>
#include <stdio.h>
#include <stdlib.h>
#include <robotutils.h>
#include <time.h>

void galette(int nb_part){

	char* used = malloc(sizeof(char) * nb_part);
	int i;
	for (i = 0; i < nb_part; i++) used[i] = 0;

	srand(time(NULL));

	int servi = 0;

	while (servi < nb_part) {
		do {
			i = rand()  % nb_part;
		} while (used[i]);

		used[i] = 1;
		
		turn(360 * i / nb_part, NULL);
		printf("Allez on se sert !!\n");
		getchar();
		
		servi++;
	}

}

int main() {
	setPosition(0, 0);
	setHeading(0);
	galette(8);
	return 0;
}


