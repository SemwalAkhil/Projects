// 22. Euler's Method
#include <iostream>
using namespace std;
double function(double x, double y)
{
    return x * y;
}
double euler(double x, double y, double end, double interval)
{
    double y1 = y + (interval * function(x, y));
    if ((x + interval) >= end)
    {
        return y1;
    }
    else
    {
        return euler(x + interval, y1, end, interval);
    }
}
int main()
{
    double xInit, yInit, xEnd, interval;
    printf("X initial : ");
    scanf("%lf", &xInit);
    printf("Y initial : ");
    scanf("%lf", &yInit);
    printf("X end : ");
    scanf("%lf", &xEnd);
    printf("Interval : ");
    scanf("%lf", &interval);
    printf("%lf", euler(xInit, yInit, xEnd, interval)); // Sample Case : 1 5 1.5 0.1 -> 8.809
    return 0;
}