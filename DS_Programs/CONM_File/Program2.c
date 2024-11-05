#include <stdio.h>
#include <math.h>

int main() {
    long long binaryNumber;
    int decimalNumber = 0, i = 0, remainder;

    // Input the binary number
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);

    // Convert binary to decimal
    while (binaryNumber != 0) {
        remainder = binaryNumber % 10; 
        binaryNumber /= 10;            
        decimalNumber += remainder * pow(2, i); 
        i++;                            
    }

    printf("Decimal equivalent is: %d\n", decimalNumber);

    return 0;
}
