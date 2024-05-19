/*
57. Write a program that computes a^b by using recursion
*/
#include <stdio.h>
int powerfun(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else
	{
		return (a * powerfun(a, b - 1));
	}
}
void main()
{
	int a, b;
	printf("Enter the a,b  : ");
	scanf("%d%d", &a, &b);
	printf("a^b is : %d", powerfun(a, b));
}