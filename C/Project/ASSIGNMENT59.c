/* 
59. Demonstration of scope or visibility and lifetime of auto storage classes
 */
#include <stdio.h>

void Function()
{
	auto int autovar = 10;
	printf("Inside Function autovar = %d\n", autovar);
}

int main()
{
	auto int autovar = 5;
	printf("Inside main autovar = %d\n", autovar);

	Function();
	return 0;
}
