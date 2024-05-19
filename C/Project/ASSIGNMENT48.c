/*
	48. To calculate sum of two floating point numbers using functions
*/
#include <stdio.h>
float add(float a,float b){
	return a+b;
}
int main(){
	float a,b;
	printf("Enter the num a & b ");
	scanf("%f%f",&a,&b);
	printf("%g + %g = %g",a,b,add(a,b));
	return 0;
}