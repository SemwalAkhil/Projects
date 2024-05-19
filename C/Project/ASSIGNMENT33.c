/*
	33. Write a menu driven program with the following options  
	1. Biggest of two numbers  
	2. Positive or negative  
	3. Factorial of a number  
	4. Exit
*/
#include <stdio.h>
void grt(void){
	int a=0;
	int b=0;
	printf("ENTER FIRST NUMBER : ");
	scanf("%d",&a);
	printf("ENTER SECOND NUMBER : ");
	scanf("%d",&b);
	a!=b	?	
	printf("GREATEST OF TWO : %d\n",
	(a>b) ? a : b)	:	
	printf("BOTH NUMBER ARE EQUAL\n");
}

void sign(void){
	int num=0;
	printf("ENTER THE NUMBER : ");
	scanf("%d",&num);
	printf("%d IS %s",num,((num==0) ? "0\n" : 
	((num>0) ? "POSITIVE\n" : "NEGATIVE\n")
	));
}
int factorial(int num){
	if (num!=0){
		return num*factorial(num-1);
	}
	return 1;
}

int main(){
	int choice=0;
	int num=0;
	while (choice != 4){
		printf("OPERATIONS \n");
		printf("1.BIGGEST OF TWO\n");
		printf("2.POSITIVE OR NEGATIVE\n");
		printf("3.FACTORIAL OF NUMBER\n");
		printf("4.EXIT\n");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				grt();
				break;
			case 2:
				sign();
				break;
			case 3:
				printf("ENTER NUMBER : ");
				scanf("%d",&num);
				printf("FACTORIAL OF %d IS : %d\n",num,factorial(num));
				break;
			case 4:
				break;
			default:
				printf("INVALID OPERATION !! TRY AGAIN\n");
				break;
		}
	}
	return 0;
}