/*
	2. To display the maximum and minimum range of some data types
*/
  
  
#include <stdio.h>
#include <limits.h>

int main() {
    printf("MIN CHAR : %d\n", CHAR_MIN);
    printf("MIN INT : %d\n", INT_MIN);
    printf("MIN SIGNED CHAR : %d\n", SCHAR_MIN);
    printf("MIN SHORT INT : %d\n", SHRT_MIN);
    printf("MIN LONG INT : %ld\n", LONG_MIN); // Use %ld for long int
    printf("MIN LONG LONG INT : %lld\n", LLONG_MIN); // Use %lld for long long int
    printf("------------------------------------------------\n");
    printf("MAX CHAR : %d\n", CHAR_MAX);
    printf("MAX INT : %d\n", INT_MAX);
    printf("MAX SIGNED CHAR : %d\n", SCHAR_MAX);
    printf("MAX SHORT INT : %d\n", SHRT_MAX);
    printf("MAX LONG INT : %ld\n", LONG_MAX); // Use %ld for long int
    printf("MAX LONG LONG INT : %lld\n", LLONG_MAX); // Use %lld for long long int
    return 0;
}