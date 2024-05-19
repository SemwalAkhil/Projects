/*
	47. To input an angle in degrees and use trigonometric function sin() to determine its value
*/
#include <stdio.h>
#include <math.h>
float pi=3.14;
int main(){
	float degree=0;
	printf("ENTER ANGLE IN DEGREES : ");
	scanf("%f",&degree);
	degree=((float)degree*(float)pi)/(float)180;
	printf("%g",sin(degree));	
	return 0;
}
