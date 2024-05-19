/*
	21. To calculate factorial of a given number entered through a keyboard
*/
#include <stdio.h>
int factorial(int num){
	if (num!=0){
		return num*factorial(num-1);
	}
	return 1;
}
int main(){
	int num=0;
	printf("ENTER NUMBER : ");
	scanf("%d",&num);
	printf("FACTORIAL OF %d : %d",num,factorial(num));
	return 0;
}