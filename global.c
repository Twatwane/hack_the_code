#include "main.h"

// Game variables
int D; // Initial capital availability
int R; // Total number of available resources
int T; // Number of game turns


// - - - INIT
Resource resources_available[100]; // Array for storing resources (adjust size as needed)
Turn turns[100]; // Array for storing turns (adjust size as needed)


// - - - DURING GAME
Resource resources_buyed[100];
Resource resources_buyed_infos[100];
int ressources_buyed_len;
int	current_turn;
