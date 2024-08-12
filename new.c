#include<stdio.h>

void main(){
    int num = 396;
    int rev = 0;
    int r = 0;
    while (num>0)  {
        r = num % 10;
        rev = (rev * 10) + r;
        num= num/10;
        printf("%d\n",rev);
    }

}