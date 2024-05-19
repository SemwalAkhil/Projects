/*
58. Write a program to find the sum of integers from 1 to n recursively
*/
#include <stdio.h>
int addfun(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return (n + addfun(n - 1));
	}
}
void main()
{
	int n;
	printf("Enter the nth term : ");
	scanf("%d", &n);
	printf("Sum for 1 to %dth is : %d", n,addfun(n));
}