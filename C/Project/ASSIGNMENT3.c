/*
	3. To declare and initialize variables of int type and type qualifiers and print their values
*/
#include <stdio.h>
int num2;//->global integer
            //->zero
int main(){
	int num1; // ->Regular integer
					 // ->Garbage Value
    register int num3; // ->register integer
    							  // ->Garbage Value
    static int num4; // ->Static integer
    						   // ->Zero

    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);

	return 0;
}