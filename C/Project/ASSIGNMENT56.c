/* 
56. Program to calculate rectangle area,perimeter,diagonal using a menu approach
 */
#include <stdio.h>
#include <math.h>
int main()
{
	int ch;
	printf("Enter your choice for rectangle \n1.Area\n2.Perimeter\n3.Diagonal \n4.Exit\n >>");
	int l, b;
	while (ch != 4)
	{
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter Length and Breadth :");
			scanf("%d%d", &l, &b);
			printf("Area : %d\n", l * b);
			break;
		case 2:
			printf("Enter Length and Breadth :");
			scanf("%d%d", &l, &b);
			printf("Perimeter: %d\n", (2 * (l + b)));
			break;
		case 3:
			printf("Enter Length and Breadth :");
			scanf("%d%d", &l, &b);
			printf("Diagonal: %f\n", sqrt(l * l + b * b));
			break;
		case 4:
			break;
		default:
			printf("Wrong choice !");
			return 0;
		}
	}
}