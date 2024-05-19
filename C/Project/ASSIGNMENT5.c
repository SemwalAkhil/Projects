/*
	5. To check result obtained by applying Relational operator
*/
#include <stdio.h>

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Check and print the results of relational operators ( == ) ( != ) ( < ) ( > ) ( <= ) ( >= )
    
    printf("%d == %d is %s\n", num1, num2, num1 == num2 ? "true" : "false");
    
    printf("%d != %d is %s\n", num1, num2, num1 != num2 ? "true" : "false");
    
    printf("%d < %d is %s\n", num1, num2, num1 < num2 ? "true" : "false");
    
    printf("%d > %d is %s\n", num1, num2, num1 > num2 ? "true" : "false");
    
    printf("%d <= %d is %s\n", num1, num2, num1 <= num2 ? "true" : "false");
    
    printf("%d >= %d is %s\n", num1, num2, num1 >= num2 ? "true" : "false");

    return 0;
}