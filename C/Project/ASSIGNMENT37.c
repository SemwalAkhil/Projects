/*
	37. Program to find and print real roots of quadratic equation
*/
#include <stdio.h>
#include <math.h>
void roots(int a, int b, int c){
	int disc=((pow(b,2))-(4*a*c));
	float r1=0;
	float r2=0;
	if (disc>=0){
		r1=(-b+pow(disc,0.5))/(2*a);
		r2=(-b-pow(disc,0.5))/(2*a);
		printf("ROOTS : %g , %g\n",r1,r2);
	}
	else{
		printf("NO REAL ROOTS\n");
	}
}
int main(){
	int a=0;
	int b=0;
	int c=0;
	printf("ENTER COEFFICIENT OF x² : ");
	scanf("%d",&a);
	printf("ENTER COEFFICIENT OF x : ");
	scanf("%d",&b);
	printf("ENTER CONSTANT TERM : ");
	scanf("%d",&c);
	roots(a,b,c);
	return 0;
}