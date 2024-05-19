/*
	38. Program to print whether entered character is lowercase alphabet or not
*/
#include <stdio.h>
int isLower(char input){
	char lower[27]="abcdefghijklmnopqrstuvwxyz";
	for (int i=0 ; i<26 ; i++){
		if (lower[i]==input){
			return 1;
		}
	}
	return 0;
}
int main(){
	char a='a';
	if (isLower(a)){
		printf("LOWERCASE\n");
	}
	else{
		printf("NOT LOWERCASE\n");
	}
	char A='A';
	if (isLower(A)){
		printf("LOWERCASE\n");
	}
	else{
		printf("NOT LOWERCASE\n");
	}
	return 0;
}