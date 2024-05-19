/*
60. Demonstration of stastic storage class
*/
#include <stdio.h>
void demoStatic()
{
	static int staticVar = 0;

	staticVar++;
	printf("Static variable: %d\n", staticVar);
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		demoStatic();
	}

	return 0;
}
