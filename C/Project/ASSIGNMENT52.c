/*
52. Program of functions with no arguments but return a value
*/
#include <stdio.h>
int add()
{
	int a = 2;
	int b = 4;
	return (a + b);
}
void main()
{
	int sum = add();
	printf("Sum: %d\n", sum);
}
