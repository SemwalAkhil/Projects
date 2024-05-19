/*
	18. To show importance of multiple assignment
	19. To interchange value of two variables without using third variables
*/
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swap the values of a and b using multiple assignment
    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}