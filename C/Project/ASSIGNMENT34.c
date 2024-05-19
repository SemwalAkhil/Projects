/*
	34. Program to print the value in different formats
*/
#include <stdio.h>

int main() {
    int number = 65;
    printf("Decimal: %d\n", number);
    printf("Hexadecimal: 0x%X\n", number);
    printf("Character: %c\n", number);
    printf("Float: %f\n", (float)number);

    return 0;
}