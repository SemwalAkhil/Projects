/*
    123.Program to demonstrate structure pointers
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

    struct data *ptr;
    ptr = &abc;
    printf("Percentage of roll no : %d of section : %c is : %g ",ptr->rollNo,ptr->section,ptr->percentage);
    return 0;
}