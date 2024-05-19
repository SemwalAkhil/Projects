/*
	42. Program that shows the working of simple calculator? A user is prompted user to enter any arithmetic operator (+, -, *, /) as a character and two numbers on which operation will be performed. The result obtained should be the equal to result of application of that arithmetic operator on two operands
*/
#include <stdio.h>
int add(int a , int b){
	return a+b;
}
int sub(int a , int b){
	return a-b;
}
int mul(int a , int b){
	return a*b;
}
float div(int a , int b){
	return (float)a/(float)b;
}
int main(){
	int choice=0;
	int a=0;
	int b=0;
	while (choice!=5){
		printf("OPERATIONS\n");
		printf("1.ADDITION\n");
		printf("2.SUBTRACTION\n");
		printf("3.MULTIPLICATION\n");
		printf("4.DIVISION\n");
		printf("5.EXIT\n");
		scanf("%d",&choice);
		if (choice!=5){
			printf("ENTER FIRST NUMBER : ");
			scanf("%d",&a);
			printf("ENTER SECOND NUMBER : ");
			scanf("%d",&b);
		}
		switch(choice){
			case 1:
				printf("%d\n\n",add(a,b));
				break;
			case 2:
				printf("%d\n\n",sub(a,b));
				break;
			case 3:
				printf("%d\n\n",mul(a,b));
				break;
			case 4:
				if (b != 0){
					printf("%g\n\n",div(a,b));
				}
				else{
					printf("ZERO DIVISION ERROR\n\n");
				}
				break;
			case 5:
				printf("EXITING CALCULATOR\n");
				break;
			default:
				printf("INVALID CHOICE!! TRY AGAIN\n\n");
				break;				
		}
	}
	return 0;
}

