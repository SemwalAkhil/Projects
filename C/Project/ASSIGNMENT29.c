/*
	29. Write a program to generate the latin square  
	1 2 3 4  
	2 3 4 1  
	3 4 1 2  
	4 1 2 3
*/
#include <stdio.h>
void latinSquare(int num){
	int start=1;
	int next=0;
	for (int i=1 ; i<=num ; i++){
		for (int j=start ; j<=num ; j++){
			printf("%d ",j);
		}
		start++;
		for (int j=1 ; j<=next ; j++){
			printf("%d ",j);
		}
		next++;
		printf("\n");
	}
}
int main(){
	latinSquare(4);
	return 0;
}