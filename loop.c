
#include "main.h"

void loop() {

	current_turn = 1;

	for (int i = 0; i < T; i++) {
		buy(); // rempli buyed avec les ressources a acheter
		active(); // set les ressources a actives ou non
		profit(); //calcul les profits

		current_turn++;
	}
}
