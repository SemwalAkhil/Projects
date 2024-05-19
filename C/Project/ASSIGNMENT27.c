/*
	27. Write a program to add first n terms of the following series 
	1/1!+2/2!+3/3!----------------n/n!
*/
#include <stdio.h>
int factorial(int num){
	if (num!=0){
		return num*factorial(num-1);
	}
	return 1;
}

float series(int num){
	float result=0;
	for (int i=1 ; i<=num ; i++){
		result+=(float)i/(float)factorial(i);
	}
	return result;
}
int main(){
	int n;
	printf("Enter the n : ");
	scanf("%d",&n);
	printf("SOLUTION FOR SERIES UPTO %d : %g",n,series(n));
	//	->%g removes additional tailing zeroes
	return 0;
}
