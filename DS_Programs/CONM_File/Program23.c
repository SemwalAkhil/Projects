// Implementing Taylor's Series method

#include<stdio.h>
#include<math.h>
float f(float x);
float fx(float x);
float fxx(float x);
float fxxx(float x);
int main()
{
    float x,x0;
    printf("Enter x and x0\n");
    scanf("%f %f",&x,&x0);
    
    float FinalValue=0;
    FinalValue=f(x0)+((x-x0)*fx(x0))/1+((x-x0)*(x-x0)*fxx(x0))/2+((x-x0)*(x-x0)*(x-x0)*fxxx(x0))/6;

    printf("%f\n",FinalValue);
    
}
float f(float x)
{
    float m;
    m=x*x*x-6*x*x+7;
    return m;
}

float fx(float x)
{
    float m;
    m=3*x*x-12*x;
    return m;
}

float fxx(float x)
{
    float m;
    m=6*x-12;
    return m;
}

float fxxx(float x)
{
    return 6;
}
