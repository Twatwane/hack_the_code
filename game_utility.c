#include "main.h"

int get_profit(int powered_building, int turn_num)
{
	return min(powered_building, turns[turn_num].TX) * turns[turn_num].TR;
}