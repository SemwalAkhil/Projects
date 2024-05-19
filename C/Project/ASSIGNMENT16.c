/*
	16. Demonstration of Nested if else construct program to find and print the biggest of three given numbers
*/
#include <stdio.h>
int grt(int a, int b, int c){
	if (a>b){
		if (a>c){
			return a;
		}
		else{
			return c;
		}
	}
	else if (b>c){
		return b;
	}
	else{
		return c;
	}
}
int main(){
	int a=0;
	int b=0;
	int c=0;
	printf("ENTER FIRST NUMBER : ");
	scanf("%d",&a);
	printf("ENTER SECOND NUMBER : ");
	scanf("%d",&b);
	printf("ENTER THIRD NUMBER : ");
	scanf("%d",&c);
	if ((a==b)&&(b==c)){
		printf("ALL EQUAL");		
	}
	else{
		printf("GREATEST : %d",grt(a,b,c));
	}
	return 0;
}