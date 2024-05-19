/*
	32. To show how characters are accessed and declared?(ASCII code)
*/
#include <stdio.h>
int charToAscii(char in)
{
	return (int)(in);
}
char asciiToChar(int in)
{
	return (char)(in);
}
int main()
{
	int A = 65;
	char a = 'A';
	printf("CHAR FOR ASCII %d : %c\n", A, asciiToChar(A));
	printf("ASCII FOR CHAR %c : %d", a, charToAscii(a));
	return 0;
}