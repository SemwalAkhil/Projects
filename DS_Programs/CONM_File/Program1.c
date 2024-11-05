#include <stdio.h>

void main() {
    int decimalNumber, remainder, binaryNumber = 0, place = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    int temp = decimalNumber;

    while (temp > 0) {
        remainder = temp % 2;
        binaryNumber += remainder * place;
        temp /= 2;
        place *= 10;
    }

    printf("Binary equivalent of %d is: %d\n", decimalNumber, binaryNumber);

}
