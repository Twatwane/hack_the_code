#include "main.h"
// Game variables
int D; // Initial capital availability
int R; // Total number of available resources
int T; // Number of game turns

Resource resources[100]; // Array for storing resources (adjust size as needed)
Turn turns[100]; // Array for storing turns (adjust size as needed)

int main(int argc, char **argv) {
    parsing();
    return 0;
}
