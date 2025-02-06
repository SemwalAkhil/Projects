#include <stdio.h>

int canCompleteCircuit(int petrol[][2], int n) {
    int totalPetrol = 0, totalDistance = 0, start = 0, currentPetrol = 0;

    for (int i = 0; i < n; i++) {
        totalPetrol += petrol[i][0];
        totalDistance += petrol[i][1];
    }

    if (totalPetrol < totalDistance) {
        return -1; // No solution
    }

    for (int i = 0; i < n; i++) {
        currentPetrol += petrol[i][0] - petrol[i][1];
        if (currentPetrol < 0) {
            start = i + 1; // Move start point
            currentPetrol = 0;
        }
    }
    
    return start;
}

int main() {
    int petrol[4][2] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int result = canCompleteCircuit(petrol, 4);
    printf("Starting point: %d\n", result);
    
    int petrol2[3][2] = {{6, 4}, {3, 6}, {7, 3}};
    result = canCompleteCircuit(petrol2, 3);
    printf("Starting point: %d\n", result);
    
    return 0;
}
