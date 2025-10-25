#include <stdio.h>
int main()
{
    int x = 10, y = 10, z = 10, a = 10, b = 10, c = 10;
    
    printf("All initially set to 10\n");
    
    printf("x++: %d x: %d\n", x++, x);
    /*
    output: x++: 10 x: 11
    x passed as arguement then increment on x and new value passed as second arguement
    */
    printf("++y: %d y: %d\n\n", ++y, y);
    /*
    output: ++y: 11 y: 11
    y increement then passed as both arguements
    */

    printf("z: %d z++: %d\n", z, z++);
    /*
    output: z: 11 z++: 10
    z passed as second arguement first then increment on z and then first arguement passed
    left to right passing
    */
    printf("a: %d ++a: %d\n\n", a, ++a);
    /*
    output: a: 11 ++a: 11
    first increment performed then a passed as first and second arguement
    */

    printf("b++: %d ++b: %d\n", b++, ++b);
    /*
    output: b++: 11 ++b: 12
    first pre increment performed then post increment then passed as first and second arguement
    */
    printf("++c: %d c++: %d\n", ++c, c++);
    /*
    output: ++c: 12 c++: 10
    passed second arguement before post increment then pre increment then passed as first arguement
    */

    /*
    CONCLUSION
    -> in general the operator with higher precedence is evaluated first in this case increement ++x or x++ operators
    -> in case operators of same precedence then evaluation is performed from right to left
    */
    return 0;
}