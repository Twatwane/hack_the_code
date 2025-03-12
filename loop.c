#include "main.h"

void active() {
	for (int i = 0; i < ressources_buyed_len; i++) {
		if (ressources_buyed[i].isObsolete) {
			return ;
		}
		ressources_buyed[i].RL--;
		if (ressources_buyed[i].RL == 0) {
			ressources_buyed[i].isObsolete = 1;
		}
		if (ressources_buyed[i].RW > 0) {
			ressources_buyed[i].RW--;
		}
		else {
			if (ressources_buyed[i].RM > 0) {
				ressources_buyed[i].RM--;
			}
			else {
				ressources_buyed[i].RM = ressources_buyed_infos[i].RM;
				ressources_buyed[i].RW = ressources_buyed_infos[i].RW;
			}
		}
		ressources_buyed[i].isActive = ressources_buyed[i].RL > 0;
	}
}

void loop() {
	for (int i = 0; i < T; i++) {
		setup_current_turn(); // rempli buyed avec les ressources a acheter
		active(); // set les ressources a actives ou non
		profit(); //calcul les profits
	}
}
