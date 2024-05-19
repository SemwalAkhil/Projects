/* 
64.To generate following design of terms of fibonacci series ;

 1

 1 1

 1 1 2

 1 1 2 3

 1 1 2 3 5

 */

#include <stdio.h>

#include <conio.h>

void main()

{

	int a, f;

	printf("Enter the no. of rows : ");

	scanf("%d", &a);

	for (int i = 1; i <= a; i++)

	{

		int x = 0, y = 1;

		for (int j = 1; j <= i; j++)

		{

			f = x + y;

			x = y;

			y = f;

			printf("%d\t", f);

		}

		printf("\n");

	}

}