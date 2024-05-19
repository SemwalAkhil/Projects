/*
	25. Write a program to accept an integer and reverse the integer.Display numbers on your screen
*/
#include <stdio.h>
#include <math.h>
int reverseNumber(int num)
{
	int reverse=0;
	while(num != 0){
		reverse=reverse*10+num%10;
		num/=10;
	}
	return reverse;
}

int main()
{
   int a;
   printf("Enter the number :  ");
   scanf("%d", &a);
	printf("REVERSE OF %d : %d",a, reverseNumber(a));
	return 0;
}