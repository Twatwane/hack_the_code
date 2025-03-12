#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Game variables
extern int D; // Initial capital availability
extern int R; // Total number of available resources
extern int T; // Number of game turns

// Turn structure
typedef struct {
    int TM, TX, TR;
} Turn;

typedef struct {
    int RI;// RI - Resource Identifier
	int RA;// RA - Activation Cost
	int RP;// RP - Periodic Maintenance Cost
	int RW;// RW - Number of consecutive active turns
	int RM;// RM - Number of downtime turns required after full cycle
	int RL;// RL - Total life cycle of the resource
	int RU;// RU - Number of buildings the resource can power per active turn
    char RT;// RT - Special effect type (A, B, C, D, E, or X)
    int RE;// RE - Special effect impact or accumulator capacity
    int isActive;
} Resource;

// - - - INIT
extern Resource resources_available[100]; // Array for storing resources (adjust size as needed)
extern Turn turns[100]; // Array for storing turns (adjust size as needed)

void parsing();


// - - - DURING GAME
// - - - DURING GAME
extern Resource resources_buyed[100];
extern int	current_turn;