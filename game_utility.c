#include "main.h"

int get_profit(int powered_buildings, int turn_index) {
    if (powered_buildings < turns[turn_index].TM) {
        return 0; // No profit if below TM
    }
    return min(powered_buildings, turns[turn_index].TX) * turns[turn_index].TR;
}