/*
	26. Write a program to print a multiplication table in the following form 
	1  2 3 4 5 6 7 8 9 10 
	2 4 6 8 10 12 14 16 18 20 
	3 6 9 12 15 18 21 24 27 30
*/
#include <stdio.h>
void table(int x,int y){
	for (int i=1 ; i<=y ; i++){
		for (int j=1 ; j<=x ; j++){
			printf("%d\t",i*j);
		}
		printf("\n");
	}		
}
int main(){
	table(10,3);
	return 0;
}