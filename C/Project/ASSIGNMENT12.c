/*
	12. To calculate the gross salary for any basic salary entered through keyboard where dearness allowance is of 20% of basic salary and house rent is 40%
*/
#include <stdio.h>
int gross(int salary){
	int sal=0;
	sal=salary-(0.2*salary);
	sal-=(0.4*salary);
	return sal;
	
}
int main(){
	int base=0;
	printf("ENTER BASIC SALARY : ");
	scanf("%d",&base);
	printf("GROSS SALARY : %d",gross(base));
	
	return 0;
}