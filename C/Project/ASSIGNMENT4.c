/*
	4. To demonstrate arithmetic operators [Addition, Subraction, Multiplication, Division, Remainder ]
*/
#include <stdio.h>

int main(){
	int a=0;
	int b=0;
	printf("ENTER FIRST NUMBER: ");
	scanf("%d",&a);
	printf("ENTER SECOND NUMBER: ");
	scanf("%d",&b);
	printf("ADDITION: %d\n",(a+b));
	printf("SUBTRACTION: %d\n",(a-b));
	printf("MULTIPLICATION: %d\n",(a*b));
	printf("REMAINDER: %d\n",(a%b));
	if (b!=0){
		printf("DIVISION: %d\n",(a/b));
	}
	else{
		printf("DIVISION: FAILED\n");
	}
	return 0;
}
