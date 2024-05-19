/*
	41. To print odd numbers betwen 1 to 10
*/
#include <stdio.h>
void printOdd(int num){
	for (int i=1 ; i<=num ; i++){
		if (i%2!=0){
			printf("%d\n",i);
		}
	}
}
int main(){
	printOdd(10);
	return 0;
}