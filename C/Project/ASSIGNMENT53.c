/*
53. Program of functions with arguments and a return value
*/
#include <stdio.h>
int add(int a, int b)
{
	return (a + b);
}
void main()
{
	int a, b;
	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);
	int sum = add(a, b);
	printf("Sum: %d\n", sum);
}