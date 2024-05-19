/*
51. Program of function with arguments but no return values
*/
#include <stdio.h>
void add(int a, int b)
{
	printf("Sum = %d", a + b);
}
void main()
{
	int a, b;
	printf("Enter a and b : ");
	scanf("%d%d", &a, &b);
	add(a, b);
}
