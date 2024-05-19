/*
	16.2. write a program to determine whether it is a leap year or not using Nested If else
*/
#include <stdio.h>
int checkLeap(int year){
	if (year%100==0){
		if (year%400==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if (year%4==0){
			return 1;
		}
		else{
			return 0;
		}
	}
}
int main(){
	int year=0;
	for (int i=0 ; i<4 ; i++){
	printf("ENTER THE YEAR : ");
	scanf("%d",&year);
	if (checkLeap(year)){
		printf("%d IS LEAP\n\n",year);
	}
	else{
		printf("%d IS NOT LEAP\n\n",year);
	}
	}
	return 0;
}
