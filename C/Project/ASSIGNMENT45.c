/*
	45. To check whether the entered character is a letter,digit or none of these?
*/
#include <stdio.h>
#include <ctype.h>
void checkChar(char input)
{
	if (isalpha(input))
	{
		printf("%c Is Letter\n", input);
	}
	else if (isdigit(input))
	{
		printf("%c Is Digit\n", input);
	}
	else
	{
		printf("None Of These\n");
	}
}
int main()
{
	char a;
	for (int i = 0; i < 3; i++){
	printf("Enter the char a : ");
	scanf(" %c", &a);
	checkChar(a);}
	return 0;
}