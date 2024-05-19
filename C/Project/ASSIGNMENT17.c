/*
	17. Write a program to take the monthly salary from the user, find and display income tax with the help of the following rule:
Monthly Salary Income Tax
10000 or more 40% of Monthly salary
7500 to more 30% of Monthly salary
7499 or less 20% of Monthly salary
*/
#include <stdio.h>
float incTax(int salary){
	float tax=0;
	(salary>=10000) ? (tax=0.4*salary) : 
	((salary>=7500) ? (tax=0.3*salary) :
	(tax=0.2*salary)) ;
	return tax;
}
int main(){
	int salary=0;
	printf("ENTER SALARY : ");
	scanf("%d",&salary);
	printf("TAX : %f",incTax(salary));
	return 0;
}