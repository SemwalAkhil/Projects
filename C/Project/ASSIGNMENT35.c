/*
	35. Program to calculate sum of first and fourth digit of four digit number
*/
#include <stdio.h>
int sumFL(int num){
	int result=0;
	result+=num%10;
	result+=num/1000;
	return result;
}
int main(){
	int num;
	printf("Enter the num : ");
	scanf("%d",&num);
	printf("SUM OF FIRST AND LAST DIGITS OF %d : %d",num,sumFL(num));
	return 0;
}