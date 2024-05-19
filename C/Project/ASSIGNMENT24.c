/*
	24. Write a program which compute a^b where a and b are of type real respectively
*/
#include <stdio.h>

int power(int num,int pow){
	int solution=1;
	if (num==0){
		solution=0;
	}
	for (int i=0 ; i<pow ; i++){
		solution*=num;
	}
	return solution;
}
int main(){
	int num=0;
	int pow=0;
	printf("ENTER NUMBER : ");
	scanf("%d",&num);
	printf("ENTER POWER : ");
	scanf("%d",&pow);
	printf("%d RAISED TO %d = %d",num,pow,power(num,pow));
	return 0;
}