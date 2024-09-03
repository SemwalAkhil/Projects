#include <iostream>
#include <cmath>
using namespace std;

double function(double x, double a, double b, double c, double d, double e)
{
    return (a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e);
}
double bisection(double lower, double upper, double a, double b, double c, double d, double e, double tolerance = 0.002)
{
    double mid = (upper + lower) / 2;
    double value = function(mid, a, b, c, d, e);
    if (value > tolerance)
    {
        return bisection(mid, upper, a, b, c, d, e);
    }
    else if (value < (-1 * tolerance))
    {
        return bisection(lower, mid, a, b, c, d, e);
    }
    else
    {
        return mid;
    }
}
int main()
{
    double a = 0, b = 0, c = 0, d = 0, e = 0, lower, upper;
    cout << "Enter coefficient of x^4 : ";
    cin >> a;
    cout << "Enter coefficient of x^3 : ";
    cin >> b;
    cout << "Enter coefficient of x^2 : ";
    cin >> c;
    cout << "Enter coefficient of x : ";
    cin >> d;
    cout << "Enter constant : ";
    cin >> e;

    // Automatically looks for possible values

    for (int i = INT16_MIN; i < INT16_MAX; i++)
    {
        if ((function(i, a, b, c, d, e) * function(i + 1, a, b, c, d, e)) <= 0)
        {
            cout << "Possible root of the equation is : " << bisection(i, i + 1, a, b, c, d, e);
            return 0;
        }
    }
    cout << "No possible root found!";

    // Taking lower and upper bounds from user
    /*
    cout << "Give a lower bound: ";
    cin >> lower;
    cout << "Give an upper bound: ";
    cin >> upper;
    cout << "Possible root of the equation is : " << bisection(lower, upper, a, b, c, d, e);
    */
    return 0;
}