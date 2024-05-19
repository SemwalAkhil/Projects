/*
	9. To determine how postfix and prefix operator increment works.
*/
#include <stdio.h>

int main(){
	int a=0;
	
	printf("a : %d\n",a);
	printf("a++ : %d\n",a++);
	printf("a : %d\n",a);
	printf("\n\n");
	
	printf("a : %d\n",a);
	printf("++a : %d\n",++a);
	printf("a : %d\n",a);
	printf("\n\n");
	
	printf("a : %d\n",a);
	printf("a-- : %d\n",a--);
	printf("a : %d\n",a);
	printf("\n\n");
	
	printf("a : %d\n",a);
	printf("--a : %d\n",--a);
	printf("a : %d\n",a);
	
	return 0;
}