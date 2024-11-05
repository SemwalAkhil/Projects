/* Program to find the root of equation x*x*x*x - x -10 =0 using Bisection Method */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define e 0.001
#define f(x) x*x*x*x - x - 10

void main()
{
    float a,b,c;
    int i=1;
    printf("\n Enter the value of a and b: ");
    scanf("%f%f",&a,&b);
    if(f(a)*f(b)>0)
    {
        printf("\n The value of a and b is not correct");
        getch();
        exit(1);
    }
    do
    {
        c=(a+b)/2;
        if(f(c)==0)
        {
            printf("\n The root of the equation is %f",c);
            break;
        }
        else if(f(a)*f(c)<0)
            b=c;
        else
            a=c;

        printf("No of interation %d",i);
        printf("root %f",c);
        printf("value of funtion %f\n",f(c));
        i++;

    }while(fabs(a-b)>=e);
    printf("\n The root of the equation is %f",c);
    getch();
}
