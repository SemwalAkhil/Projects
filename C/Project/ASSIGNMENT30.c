/*
	30. Write a program to find whether entered number is pallindrome or not
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
int pallindromeCheck(int num){
	return (reverseNumber(num)==num);
}
int main(){
	int num;
	printf("Enter the num : ");
	scanf("%d",&num);
	printf("%s", pallindromeCheck(num) ? "PALLINDROME" : "NOT PALLINDROME");
	return 0;
}