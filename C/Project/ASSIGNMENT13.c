/*
	13. to check whether an entered number is even or odd
*/
#include <stdio.h>

int main(){
	int num=0;
	printf("ENTER THE NUMBER : ");
	scanf("%d",&num);
	printf("%d IS %s",num,((num%2==0) ? "EVEN" : "ODD"));
	return 0;
}