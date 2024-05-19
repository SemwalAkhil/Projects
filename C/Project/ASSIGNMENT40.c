/*
	40.To keep on adding integers from 1 to 30 and print the integer when sum exceeds 100
*/
#include <stdio.h>
void sum30(void){
	int sum=0,m;
	for (int i=1 ; i<=30 ; i++ ){
		m=i;
		sum+=i;
		if (sum>100){
			break;
		}
	}
	printf("At %d SUM IS %d\n",m,sum);
}
int main(){
	sum30();
	return 0;
}