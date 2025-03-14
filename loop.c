#include "main.h"

void active() {
	for (int i = 0; i < ressources_buyed_len; i++) {
		if (ressources_buyed[i].isObsolete) {
			ressources_buyed[i].isActive = 0;
			continue ;
		}
		ressources_buyed[i].RL--;
		if (ressources_buyed[i].RL <= 0) {
			ressources_buyed[i].isObsolete = 1;
		}
		if (ressources_buyed[i].RW > 0) {
			ressources_buyed[i].RW--;
		}
		else {
			if (ressources_buyed[i].RM > 1) {
				ressources_buyed[i].RM--;
			}
			else {
				ressources_buyed[i].RM = ressources_buyed_infos[i].RM;
				ressources_buyed[i].RW = ressources_buyed_infos[i].RW;
			}
		}
		ressources_buyed[i].isActive = ressources_buyed[i].RW > 0;
		// printf("isActive%d\n", ressources_buyed[i].isActive);
	}
}

void payMaintenance () {
	
	for (int i = 0; i < ressources_buyed_len; i++) {
		if (ressources_buyed[i].isObsolete) {
			continue ;
		}
		D -= ressources_buyed[i].RP;
		if (D < 0) {
			printf("Erreur lors de l'entretient de la ressource %d\n", i);
		}
	}

}

void loop() {

	if (DEBUG_MODE)
		printf("\nSTART SIMULATION (output) :\n");
	current_turn = 1;

	for (int i = 0; i < T; i++) {
		setup_current_turn(); // rempli buyed avec les ressources a acheter
		payMaintenance();
		apply_turn_effects(i);
		if (DEBUG_MODE)
			print_status();
		active(); // set les ressources a actives ou non et les update


		current_turn++;
	}
}
