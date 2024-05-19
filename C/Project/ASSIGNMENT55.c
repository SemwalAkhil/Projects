/*
55. To reduce a given number to a single number
*/
#include <stdio.h>
int singledigit(int n)
{
	int s = 0;
	while (n != 0)
	{
		int r = n % 10;
		s = s + r;
		n = n / 10;
	}
	return s;
}
void main()
{
	int n;
	printf("Enter the No.: ");
	scanf("%d", &n);
	while (n / 10 != 0)
	{
		n = singledigit(n);
	}
	printf("The single number is : %d", n);
}