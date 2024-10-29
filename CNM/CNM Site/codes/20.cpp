// 20. Runge Kutta 2nd Order Method
#include <iostream>
using namespace std;
double function(double x, double y)
{
    return x * y;
}
double rungeKutta(double x, double y, double h, double upper)
{
    double k1 = h * function(x, y);
    double k2 = h * function(x + h, y + k1);
    double y1 = y + (k1 + k2) * (1.0 / 2.0);
    if ((x + h) >= upper)
    {
        return y1;
    }
    else
    {
        return rungeKutta(x + h, y1, h, upper);
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
    printf("%lf", rungeKutta(xInit, yInit, interval, xEnd)); // Sample Case : 1 5 1.5 0.1 -> 9.3264
    return 0;
}