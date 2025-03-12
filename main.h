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
extern Resource resources_buyed_infos[100];
extern int ressources_buyed_len = 0;
extern int	current_turn = 0;





//game_utility.c
int get_profit(int powered_building, int turn_num);



// function.c
/* SPECIAL CAPACITIES (Sbject page3) */

// Function A: Adjusts the number of powered buildings
// ----------------------------------------------
// Smart Meter (RT = 'A') modifies the number of powered buildings.
// Green Smart Meter: Increases the number of powered buildings.
// Non-Green Smart Meter: Decreases the number of powered buildings.
// This adjustment is proportional to the 'RE' percentage.
void a(int* powered_buildings);

// Function B: Adjusts TM and TX thresholds
// ----------------------------------------------
// Distribution Facility (RT = 'B') modifies the building limits:
// Green Resource: Increases both TM (minimum) and TX (maximum) thresholds.
// Non-Green Resource: Decreases TM and TX thresholds.
// This helps control the required and maximum possible building counts.
void b();

// Function C: Adjusts lifespan (RL) for newly purchased resources
// ---------------------------------------------------------------
// Maintenance Plan (RT = 'C') modifies the lifespan of resources.
// Green Resource: Extends the lifespan (RL) of new resources.
// Non-Green Resource: Reduces the lifespan (RL) of new resources (min 1 turn).
void c();

// Function D: Adjusts profit per powered building (TR)
// -----------------------------------------------------
// Renewable Plant (RT = 'D') modifies the profit value per powered building.
// Green Resource: Increases profit per building.
// Non-Green Resource: Decreases profit per building (minimum 0).
void d();

// Function E: Manages accumulator logic
// ---------------------------------------
// Accumulator (RT = 'E') stores surplus powered buildings to use later.
// Surpluses are drawn during deficit turns to ensure the minimum TM is met.
void e(int* surplus, int* deficit);

// Function X: Base Resource logic (no special effect)
// ----------------------------------------------------
// Base Resource (RT = 'X') has no impact on the game mechanics.
void x();