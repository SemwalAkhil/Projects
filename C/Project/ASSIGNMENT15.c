/*
	15. To find greatest of three numbers using logical operator
*/
#include <stdio.h>

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
	
	((a!=b)||(b!=c))	?	//->checks if all number equal
		printf("GREATEST OF THREE : %d",
		((a>b)&&(a>c))?	//->checks if a greatest 
			a :
			(((b>a)&&(b>c))?	//->if a not the greatest checks if b is greatest 
				b : 
				c))	//->if a or b not the greatest then c is greatest
		:	
		printf("ALL NUMBERS ARE EQUAL"); 
	return 0;
}