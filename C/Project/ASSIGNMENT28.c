/*
	28. Write a program to print the figure  
	*  
	**  
	***  
	****  
	*****
*/
#include <stdio.h>
void figure(int x,int y){
	for (int i=0 ; i<x ; i++){
		for (int j=0 ; j<=i ; j++){
			printf("*");
		}
		printf("\n");
	}
}
int main(){
	figure(5,4);
	return 0;
}