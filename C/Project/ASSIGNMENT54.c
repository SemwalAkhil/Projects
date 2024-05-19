/*
54. To check whether a number given by the user is Buzz number or not
*/
#include <stdio.h>
void main()
{
	int n;
	printf("Enter the no. : ");
	scanf("%d", &n);
	int m = n, s = 0;
	while (m != 0)
	{
		int r = m % 10;
		s = s + r;
		m = m / 10;
	}
	if (n % 7 == 0)
	{
		printf("%d is Buzz number ", n);
	}
	else if (n % 10 == 7)
	{
		printf("%d is Buzz number ", n);
	}
	else if (s == 7)
	{
		printf("%d is Buzz number ", n);
	}
	else
	{
		printf("%d is not  a Buzz number ", n);
	}
}