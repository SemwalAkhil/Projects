/*
	39.To show that break transfer control out of the enclosing loop only
*/
#include <stdio.h>

int main() {
    int i, j;
    for (i = 1; i <= 3; i++) {
        printf("Outer loop iteration %d\n", i);
        for (j = 1; j <= 3; j++) {
            printf("\tInner loop iteration %d\n", j);
            if (j == 2) {
                printf("\tBreaking out of inner loop...\n");
                break; 
                // This break only exits the inner loop.
            }
        }
    }
printf("Out of the main loop");
    return 0;
}