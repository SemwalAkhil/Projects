/*
	20. To interchange value of two variables with using third variables
*/
#include <stdio.h>
int swap(int* a, int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int a= 10;
	int b= 20;
	printf("A : %d B : %d\n",a,b);
	swap(&a,&b);
	printf("A : %d B : %d",a,b);
	return 0;
}
