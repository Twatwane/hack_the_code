#include "main.h"

void active(Resource *r) {
	Resource info = *r;
	if ((*r).isObsolete) {
		return ;
	}
	(*r).RL--;
	if ((*r).RL == 0) {
		(*r).isObsolete = 1;
	}
	if ((*r).RW > 0) {
		(*r).RW--;
	}
	else {
		if ((*r).RM > 0) {
			(*r).RM--;
		}
		else {
			(*r).RM = info.RM;
			(*r).RW = info.RW;
		}
	}
	(*r).isActive = (*r).RL > 0;
}

int rentability(Resource r, int day) { // renvoie la rentabilite d'une ressource pour un nombre de jour day
	int cost = 0;
	int activity = 0;
	int durability = 0;

	cost += r.RA;
	while (!r.isObsolete) {
		
	}
}
