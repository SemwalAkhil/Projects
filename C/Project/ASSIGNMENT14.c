/*
	14. to test whether an entered number is positive , negative or zero
*/
#include <stdio.h>

int main(){
	int num=0;
	printf("ENTER THE NUMBER : ");
	scanf("%d",&num);
	printf("%d IS %s",num,((num==0) ? "0" : 
	((num>0) ? "POSITIVE" : "NEGATIVE")
	));
	return 0;
}