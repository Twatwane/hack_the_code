#include "main.h"

void turn(Resource *r) {
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

int rentability(Resource r, int day, int start) { // renvoie la rentabilite d'une ressource pour un nombre de jour day
	int cost = 0;
	int profit = 0;
	int activity = 0;
	int i = 0;

	cost += r.RA;
	while (!r.isObsolete && i < day) {
		if (r.isActive)
			activity++;
		turn(&r);
		if (r.isActive) {
			profit += get_profit(r.RU ,i + start);
		}
		cost -= r.RP;
		i++;
	}
	return (profit - cost);
}
