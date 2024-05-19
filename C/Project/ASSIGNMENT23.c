/*
	23. Write a program to find and print the n terms of Fibonnaci series : 0,1,1,2,3,5,8,13,21,34,55
*/
#include <stdio.h>
void fibonacci(int num){
	int a=0;
	int b=1;
	int temp=0;
	for (int i=2; i<(num+2); i++){
		printf("%d ",a);
		temp=b;
		b=a+b;
		a=temp;
	}
}
int main(){
	fibonacci(11);
	return 0;
}