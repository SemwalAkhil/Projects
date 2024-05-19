/*
	11. To calculate compound interest when principle amount, rate of interest and number of years are given.
*/
#include <stdio.h>
#include <math.h>
float compInterest(int principal, float rate, int year){
	float amount=0;
	float interest=0;
	amount=pow((1+(rate/100)),year);
	amount*=principal;
	interest=amount-principal;
	return interest;
}
int main(){
	int principal=0;
	float rate=0;
	int year=0;
	printf("PRINCIPAL AMOUNT: ");
	scanf("%d",&principal);
	printf("RATE (in %%): ");
	scanf("%f",&rate);
	printf("YEAR: ");
	scanf("%d",&year);
	printf("INTEREST: %g", compInterest(principal,rate,year));
	
	return 0;
}
