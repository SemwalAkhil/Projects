/*
    119.Program to demonstrate use of piece-meal to copy the structure elements using assignment operator
*/
#include <stdio.h>
int main(){
    struct data
    {
        int rollNo;
        char section;
        float percentage;
    };
    struct data a1,b1;
    a1.percentage = 88.6;
    a1.rollNo = 33;
    a1.section = 'a';

    b1.percentage = a1.percentage;
    b1.rollNo = a1.rollNo;
    b1.section = a1.section;

    printf("Percentage of roll no : %d of section : %c is : %g \n",a1.rollNo,a1.section,a1.percentage);
    printf("Percentage of roll no : %d of section : %c is : %g \n",b1.rollNo,b1.section,b1.percentage);
    return 0;
}