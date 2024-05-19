/*
	22. To enter numbers and print them until user enters 0
*/
#include <stdio.h>

int main(){
	int num=0;
	do{
		printf("ENTER NUMBER : ");
		scanf("%d",&num);
		printf("NUMBER IS %d\n",num);
	}while (num!=0);
	return 0;
}