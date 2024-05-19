/*
	6. To check whether a number is divisible by 3 and 5 or by 3 or 5 .
*/
#include <stdio.h>

void check(int a){
	if ((a%3==0)&&(a%5==0)){
		printf("DIVISBLE BY 3 AND 5\n");
	}
	else if((a%3==0)||(a%5==0)){
			printf("DIVISBLE BY 3 OR 5\n");
		}
	else{
			printf("NOT DIVISIBLE BY 3 OR 5");
		}
}
int main(){
	int num=0;
	printf("ENTER THE NUMBER: ");
	scanf("%d",&num);
	check(num);
	return 0;
}