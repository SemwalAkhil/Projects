/*
    105.Demonstration of assignment of complete structure
*/
#include <stdio.h>
#include <string.h>
int main(){
    struct marks
    {
        char name[20];
        int rollNo,sub1,sub2,sub3;
    };
    struct marks a;
    strcpy(a.name,"akh\0");
    a.rollNo=33;
    a.sub1=80;
    a.sub2=85;
    a.sub3=89;
    printf("Name : %s RollNo : %d Sub1 : %d Sub2 : %d Sub3 : %d",a.name,a.rollNo,a.sub1,a.sub2,a.sub3);
    
    return 0;
}