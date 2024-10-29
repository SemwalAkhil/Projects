// 21. Runge Kutta 4th Order Method
#include <iostream>
using namespace std;
double function(double x, double y)
{
    return x + (y * y);
}
double rungeKutta(double x, double y, double h, double upper)
{
    double k1 = h * function(x, y);
    double k2 = h * function(x + (h / 2.0), y + (k1 / 2.0));
    double k3 = h * function(x + (h / 2.0), y + (k2 / 2.0));
    double k4 = h * function(x + h, y + k3);
    double y1 = y + (k1 + (2.0 * k2) + (2.0 * k3) + k4) * (1.0 / 6.0);
    // printf("%lf\n", y1);
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
    printf("%lf", rungeKutta(xInit, yInit, interval, xEnd)); // Sample Case : 0 1 0.1 0.2 ->1.2736
    return 0;
}