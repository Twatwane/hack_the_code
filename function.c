#include "main.h"

// Function A: Adjusts the number of powered buildings
// ----------------------------------------------
// Smart Meter (RT = 'A') modifies the number of powered buildings.
// Green Smart Meter: Increases the number of powered buildings.
// Non-Green Smart Meter: Decreases the number of powered buildings.
// This adjustment is proportional to the 'RE' percentage.
void a(int* powered_buildings) {
    for (int i = 0; i < R; i++) {
        if (ressources_buyed[i].RT == 'A') {
            int adjustment = (*powered_buildings * ressources_buyed[i].RE) / 100;

            if (ressources_buyed[i].RE > 0) { // Green Smart Meter (increase buildings)
                *powered_buildings += adjustment;
            } else { // Non-Green Smart Meter (decrease buildings)
                *powered_buildings = (*powered_buildings + adjustment < 0) 
                                     ? 0 
                                     : *powered_buildings + adjustment;
            }
        }
    }
}

// Function B: Adjusts TM and TX thresholds
// ----------------------------------------------
// Distribution Facility (RT = 'B') modifies the building limits:
// Green Resource: Increases both TM (minimum) and TX (maximum) thresholds.
// Non-Green Resource: Decreases TM and TX thresholds.
// This helps control the required and maximum possible building counts.
void b() {
    for (int i = 0; i < R; i++) {
        if (ressources_buyed[i].RT == 'B') {
            for (int t = 0; t < T; t++) {
                int adjustment = (turns[t].TM * ressources_buyed[i].RE) / 100;
                if (ressources_buyed[i].RE > 0) { // Green Resource
                    turns[t].TM += adjustment;
                    turns[t].TX += adjustment;
                } else { // Non-Green Resource
                    turns[t].TM = (turns[t].TM - adjustment < 0) ? 0 : turns[t].TM - adjustment;
                    turns[t].TX = (turns[t].TX - adjustment < 0) ? 0 : turns[t].TX - adjustment;
                }
            }
        }
    }
}

// Function C: Adjusts lifespan (RL) for newly purchased resources
// ---------------------------------------------------------------
// Maintenance Plan (RT = 'C') modifies the lifespan of resources.
// Green Resource: Extends the lifespan (RL) of new resources.
// Non-Green Resource: Reduces the lifespan (RL) of new resources (min 1 turn).
void c() {
    for (int i = 0; i < R; i++) {
        if (ressources_buyed[i].RT == 'C') {
            for (int j = 0; j < R; j++) {
                int adjustment = (ressources_buyed[j].RL * ressources_buyed[i].RE) / 100;
                if (ressources_buyed[i].RE > 0) { // Green Resource
                    ressources_buyed[j].RL += adjustment;
                } else { // Non-Green Resource
                    ressources_buyed[j].RL = (ressources_buyed[j].RL - adjustment < 1) ? 1 : ressources_buyed[j].RL - adjustment;
                }
            }
        }
    }
}

// Function D: Adjusts profit per powered building (TR)
// -----------------------------------------------------
// Renewable Plant (RT = 'D') modifies the profit value per powered building.
// Green Resource: Increases profit per building.
// Non-Green Resource: Decreases profit per building (minimum 0).
void d() {
    for (int i = 0; i < R; i++) {
        if (ressources_buyed[i].RT == 'D') {
            for (int t = 0; t < T; t++) {
                int adjustment = (turns[t].TR * ressources_buyed[i].RE) / 100;
                if (ressources_buyed[i].RE > 0) { // Green Resource
                    turns[t].TR += adjustment;
                } else { // Non-Green Resource
                    turns[t].TR = (turns[t].TR - adjustment < 0) ? 0 : turns[t].TR - adjustment;
                }
            }
        }
    }
}

// Function E: Manages accumulator logic
// ---------------------------------------
// Accumulator (RT = 'E') stores surplus powered buildings to use later.
// Surpluses are drawn during deficit turns to ensure the minimum TM is met.
void e(int* surplus, int* deficit) {
    for (int i = 0; i < R; i++) {
        if (ressources_buyed[i].RT == 'E') {
            if (*surplus > 0) {
                *deficit = (*deficit > *surplus) ? 0 : *deficit - *surplus;
            }
        }
    }
}

// Function X: Base Resource logic (no special effect)
// ----------------------------------------------------
// Base Resource (RT = 'X') has no impact on the game mechanics.
void x() {
    // No special logic needed for base resources
}

// Function to apply effects based on purchased resources
void apply_effects(int* powered_buildings, int* surplus, int* deficit) {
    for (int i = 0; i < ressources_buyed_len; i++) {
        switch (ressources_buyed[i].RT) {
            case 'A':
                a(powered_buildings); // Smart Meter (adjusts powered buildings)
                break;
            case 'B':
                b(); // Distribution Facility (adjusts TM and TX thresholds)
                break;
            case 'C':
                c(); // Maintenance Plan (adjusts lifespan of resources)
                break;
            case 'D':
                d(); // Renewable Plant (adjusts profit per powered building)
                break;
            case 'E':
                e(surplus, deficit); // Accumulator (manages surplus storage)
                break;
            case 'X':
                x(); // Base Resource (no effect)
                break;
            default:
                if (DEBUG_MODE) {
                    printf("[DEBUG] Unknown resource effect type: %c\n", ressources_buyed[i].RT);
                }
                break;
        }
    }
}

// Example of integration with turn logic
void apply_turn_effects(int turn_index) {
    int powered_buildings = get_powered_buildings();
    int surplus = 0; // Initialize surplus
    int deficit = 0; // Initialize deficit

    // Apply effects from active resources
    apply_effects(&powered_buildings, &surplus, &deficit);

    // Calculate profit after applying effects
    D += get_profit(powered_buildings, turn_index);
}
