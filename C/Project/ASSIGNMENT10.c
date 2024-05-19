/*
	10. To calculate the aggregate and percentage marks obtained by the student in three subjects.
*/
#include <stdio.h>

int main(){
	int a=0;
	int b=0;
	int c=0;
	printf("ENTER MARKS : ");
	scanf("%d",&a);
	printf("ENTER MARKS : ");
	scanf("%d",&b);
	printf("ENTER MARKS : ");
	scanf("%d",&c);
	printf("AGGREGATE MARKS : %d\n",a+b+c);
	printf("PERCENTAGE : %g",((float)a+b+c)/((float)3));
	return 0;
}
