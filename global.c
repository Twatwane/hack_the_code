#include "main.h"

// Game variables
int D; // Initial capital availability
int R; // Total number of available resources
int T; // Number of game turns


// - - - INIT
Resource ressources_available[100]; // Array for storing resources (adjust size as needed)
Turn turns[100]; // Array for storing turns (adjust size as needed)


// - - - DURING GAME
Resource ressources_buyed[100];
Resource ressources_buyed_infos[100];
int ressources_buyed_len = 0;
int	current_turn = 0;
int	nb_ressources_buyed_current_turn = 0;