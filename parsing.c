#include "main.h"

// Parsing function
void parsing() {
    FILE *file = fopen("0-demo.txt", "r");

    fscanf(file, "%d %d %d", &D, &R, &T); // Read initial values

    // Reading ressources_available
    for (int i = 0; i < R; i++) {
        fscanf(file, "%d %d %d %d %d %d %d %c", 
               &ressources_available[i].RI, &ressources_available[i].RA, &ressources_available[i].RP, 
               &ressources_available[i].RW, &ressources_available[i].RM, &ressources_available[i].RL, 
               &ressources_available[i].RU, &ressources_available[i].RT);

        if (ressources_available[i].RT == 'X') {
            ressources_available[i].RE = -1; // If 'X', set RE to -1
        } else {
            fscanf(file, "%d", &ressources_available[i].RE); // Otherwise read normally
        }
    }

    // Reading turns
    for (int i = 0; i < T; i++) {
        fscanf(file, "%d %d %d", &turns[i].TM, &turns[i].TX, &turns[i].TR);
    }

    fclose(file);

    // Display extracted data for verification
	if (DEBUG_MODE)
	{
		printf("D: %d, R: %d, T: %d\n", D, R, T);
		printf("Resources:\n");
		for (int i = 0; i < R; i++) {
			printf("%d %d %d %d %d %d %d %c %d\n", 
				ressources_available[i].RI, ressources_available[i].RA, ressources_available[i].RP,
				ressources_available[i].RW, ressources_available[i].RM, ressources_available[i].RL,
				ressources_available[i].RU, ressources_available[i].RT, ressources_available[i].RE);
		}

		printf("Turns:\n");
		for (int i = 0; i < T; i++) {
			printf("%d %d %d\n", turns[i].TM, turns[i].TX, turns[i].TR);
		}
	}
}