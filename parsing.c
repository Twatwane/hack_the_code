#include "main.h"

// Parsing function
void parsing() {
    FILE *file = fopen("0-demo.txt", "r");

    fscanf(file, "%d %d %d", &D, &R, &T); // Read initial values

    // Reading resources_available
    for (int i = 0; i < R; i++) {
        fscanf(file, "%d %d %d %d %d %d %d %c", 
               &resources_available[i].RI, &resources_available[i].RA, &resources_available[i].RP, 
               &resources_available[i].RW, &resources_available[i].RM, &resources_available[i].RL, 
               &resources_available[i].RU, &resources_available[i].RT);

        if (resources_available[i].RT == 'X') {
            resources_available[i].RE = -1; // If 'X', set RE to -1
        } else {
            fscanf(file, "%d", &resources_available[i].RE); // Otherwise read normally
        }
    }

    // Reading turns
    for (int i = 0; i < T; i++) {
        fscanf(file, "%d %d %d", &turns[i].TM, &turns[i].TX, &turns[i].TR);
    }

    fclose(file);

    // Display extracted data for verification
    printf("D: %d, R: %d, T: %d\n", D, R, T);
    printf("Resources:\n");
    for (int i = 0; i < R; i++) {
        printf("%d %d %d %d %d %d %d %c %d\n", 
               resources_available[i].RI, resources_available[i].RA, resources_available[i].RP,
               resources_available[i].RW, resources_available[i].RM, resources_available[i].RL,
               resources_available[i].RU, resources_available[i].RT, resources_available[i].RE);
    }

    printf("Turns:\n");
    for (int i = 0; i < T; i++) {
        printf("%d %d %d\n", turns[i].TM, turns[i].TX, turns[i].TR);
    }
}