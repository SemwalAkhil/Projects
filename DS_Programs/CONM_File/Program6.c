/* Program to find the root of equation x*x*x*x - x - 10 = 0 using Newton Raphson Method */
#include<stdio.h>
#include<math.h>
#define e 0.001

float f(float x)
{
    return (x*x*x*x - x -10);
}

float differentiate(float x)
{
    return (4*x*x*x - 1);
}

int main()
{
    int maxIteration,i;
    float x1,x2,x,x0;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);

//......Compute x1 and x2............. 
   
   do
   {
        printf("Enter the value of x1 and x2(starting boundary)");
        scanf("%f%f",&x1,&x2);
        if(f(x1)*f(x2)>0)
        {
           printf("Boundary Values are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;
        }
    } while(1);

    //find x0
    if(fabs(f(x1)) < fabs(f(x2)))
        x0 = x1;
    else
        x0 = x2;    

    //Apply Successive approximation to find the root b/w x1 and x2
    //..........Find root............   
    for(i=1;i<=maxIteration;i++)
    {
      x = x0 - (f(x0)/differentiate(x0));  
      
      if(fabs(x-x0)<e)
      {       
            printf("Iterations=%d  Final Root=%f value of function %f\n",i,x,f(x));
           return 0;
      }      
      printf("Iterations=%d  Roots=%f value of function %f\n",i,x,f(x)); 
      x0=x;
    }
    printf("Root=%f  Total Iterations=%d, value of function %f\n",x,--i,f(x));
    return 0;
}