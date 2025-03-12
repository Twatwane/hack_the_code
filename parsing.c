#include "main.h"

// Parsing function
void parsing() {
    FILE *file = fopen("0-demo.txt", "r");

    fscanf(file, "%d %d %d", &D, &R, &T); // Read initial values

    // Reading resources
    for (int i = 0; i < R; i++) {
        fscanf(file, "%d %d %d %d %d %d %d %c", 
               &resources[i].RI, &resources[i].RA, &resources[i].RP, 
               &resources[i].RW, &resources[i].RM, &resources[i].RL, 
               &resources[i].RU, &resources[i].RT);

        if (resources[i].RT == 'X') {
            resources[i].RE = -1; // If 'X', set RE to -1
        } else {
            fscanf(file, "%d", &resources[i].RE); // Otherwise read normally
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
               resources[i].RI, resources[i].RA, resources[i].RP,
               resources[i].RW, resources[i].RM, resources[i].RL,
               resources[i].RU, resources[i].RT, resources[i].RE);
    }

    printf("Turns:\n");
    for (int i = 0; i < T; i++) {
        printf("%d %d %d\n", turns[i].TM, turns[i].TX, turns[i].TR);
    }
}