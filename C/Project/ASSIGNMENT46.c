/*
	46. To input a character and if it is a letter , determine whether it is a vowel or a consonant
*/
#include <stdio.h>
int checkLetter(char letter){
	char vowel[]="aeiouAEIOU";
	;
	for (int i=0 ; i<10 ; i++){
		if (letter==vowel[i]){
			printf("VOWEL\n");
			return 1;
		}
	}
	printf("Consonant\n");
	return 1;
}
int main(){
	char a;
	for (int i = 0; i < 3; i++){
	printf("Enter the char a : ");
	scanf(" %c", &a);
	checkLetter(a);}
	return 0;
}