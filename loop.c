#include "main.h"

void active() {
	for (int i = 0; i < ressources_buyed_len; i++) {
		resources_buyed[i].RL--;
		if (resources_buyed[i].RW > 0) {
			resources_buyed[i].RW--;
		}
		// else {
		// 	if ()
		// }
	}
}

void loop() {
	for (int i = 0; i < T; i++) {
		buy(); // rempli buyed avec les ressources a acheter
		active(); // set les ressources a actives ou non
		profit(); //calcul les profits
	}
}
