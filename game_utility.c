#include "main.h"

int get_profit(int powered_buildings, int turn_index)
{

    if (powered_buildings < turns[turn_index].TM)
	{
		if (DEBUG_MODE)
			printf("profit calcul : NO PROFIT\n");

        return 0; // No profit if below TM
    }

	if (powered_buildings < turns[turn_index].TX)
	{
		if (DEBUG_MODE)
		{
			printf("profit calcul : %i * %i\n", powered_buildings, turns[turn_index].TR);
		}

		return powered_buildings * turns[turn_index].TR;
	}

	if (DEBUG_MODE)
	{
		printf("profit calcul : %i * %i\n", turns[turn_index].TX, turns[turn_index].TR);
	}
    return turns[turn_index].TX * turns[turn_index].TR;
}

int get_powered_buildings() {
    int total_powered = 0;
    for (int i = 0; i < R; i++) {
        if (ressources_buyed[i].isActive)
            total_powered += ressources_buyed[i].RU;
    }
    a(&total_powered); // Apply Smart Meter adjustments
    return total_powered;
}
