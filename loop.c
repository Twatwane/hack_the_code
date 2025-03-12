
#include "main.h"

Resource resourcesBuyed[500];

void loop() {
	for (int i = 0; i < T; i++) {
		buy(); // rempli buyed avec les ressources a acheter
		active(); // set les ressources a actives ou non
		profit(); //calcul les profits
	}
}
