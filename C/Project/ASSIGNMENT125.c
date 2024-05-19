/*
    125.Program to demonstrate union
*/
#include <stdio.h>
int main(){
    union data
    {
        int rollNo;
        char section;
        float percentage;
    };
    union data abc;
    abc.percentage = 88;
    abc.rollNo = 33;
    abc.section = 'a';

    printf("Percentage of roll no : %d of section : %c is : %g ",abc.rollNo,abc.section,abc.percentage);
    // last assigned gets the correct value
    
    return 0;
}