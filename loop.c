#include "main.h"

void active() {
	for (int i = 0; i < ressources_buyed_len; i++) {
		if (resources_buyed[i].isObsolete) {
			return ;
		}
		resources_buyed[i].RL--;
		if (resources_buyed[i].RL == 0) {
			resources_buyed[i].isObsolete = 1;
		}
		if (resources_buyed[i].RW > 0) {
			resources_buyed[i].RW--;
		}
		else {
			if (resources_buyed[i].RM > 0) {
				resources_buyed[i].RM--;
			}
			else {
				resources_buyed[i].RM = resources_buyed_infos[i].RM;
				resources_buyed[i].RW = resources_buyed_infos[i].RW;
			}
		}
		resources_buyed[i].isActive = resources_buyed[i].RL > 0;
	}
}

void loop() {
	for (int i = 0; i < T; i++) {
		setup_current_turn(); // rempli buyed avec les ressources a acheter
		active(); // set les ressources a actives ou non
		profit(); //calcul les profits
	}
}
