/*
61. To calculate Factorial using recursion
*/
#include <stdio.h>
long long fact(long n)
{
	if (n <= 1)
	{
		return (1);
	}
	else
	{
		return (n * fact(n - 1));
	}
}
void main()
{
	long n;
	printf("Enter the no. for its factorial : ");
	scanf("%ld", &n);
	printf("Factorial of %ld is %ld",n, fact(n));
}