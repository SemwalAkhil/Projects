/*
	7. To find greatest of two numbers using conditional operator
*/
#include <stdio.h>

int main(){
	int a=0;
	int b=0;
	printf("ENTER FIRST NUMBER : ");
	scanf("%d",&a);
	printf("ENTER SECOND NUMBER : ");
	scanf("%d",&b);
	
	a!=b	?	
	printf("GREATEST OF TWO : %d",
	(a>b) ? a : b)	:	
	printf("BOTH NUMBER ARE EQUAL");
	
	return 0;
}