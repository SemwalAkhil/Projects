/*
    117.Program to illustrate (char,float,int)data type of structure
*/
#include <stdio.h>
int main(){
    struct data
    {
        int rollNo;
        char section;
        float percentage;
    };
    struct data abc;
    abc.percentage = 88.6;
    abc.rollNo = 33;
    abc.section = 'a';

    printf("Percentage of roll no : %d of section : %c is : %g ",abc.rollNo,abc.section,abc.percentage);
    return 0;
}