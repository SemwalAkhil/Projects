// ENTER THE NUMBER FROM THE USER AND ADD ALL DIGITS OF THE NUMBER USING RECURSION.

#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = sumOfDigits(num);
    printf("The sum of the digits is: %d\n", result);

    return 0;
}
