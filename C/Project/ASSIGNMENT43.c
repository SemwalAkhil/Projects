/*
	43. Program to demonstrate automatic type conversion
*/
#include <stdio.h>

int main(){
    int num1;
    double num2;
    printf("Enter the num1(int) & num2(float) : ");
	scanf("%d%d",&num1,&num2);
    // Automatic type conversion from int to double
    double result = num1 + num2;

    printf("Result: %g\n", result);

    return 0;
}