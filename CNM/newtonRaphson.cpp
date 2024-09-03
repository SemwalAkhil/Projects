#include <iostream>
#include <cmath>
using namespace std;
double function(double x, double a, double b, double c, double d, double e)
{
    return (a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e);
}
// Accuracy of newton raphson method relies highly on differentiation, decrease tolerance to get more accurate results
double differentiator(double x, double a, double b, double c, double d, double e, double tolerance = 0.000000000000001)
{
    return (function(x + tolerance, a, b, c, d, e) - function(x, a, b, c, d, e)) / tolerance;
}
double newtonRaphson(double point, double a, double b, double c, double d, double e, double tolerance = 0.002)
{
    double x = point - (function(point, a, b, c, d, e) / differentiator(point, a, b, c, d, e));
    double value = function(x, a, b, c, d, e);
    if (abs(value) < tolerance)
    {
        return newtonRaphson(x, a, b, c, d, e);
    }
    else
    {
        return x;
    }
}
int main()
{
    double a = 0, b = 0, c = 0, d = 0, e = 0, tolerance = 0.002, guess;
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

    for (double i = INT16_MIN; i < INT16_MAX; i++)
    {
        if ((function(i, a, b, c, d, e) * function(i + 1, a, b, c, d, e)) <= 0)
        {
            cout << "Possible root of the equation is : " << newtonRaphson(i, a, b, c, d, e);
            return 0;
        }
    }
    cout << "No possible root found!";

    // Taking lower and upper bounds from user
    /*
    cout << "Give a lower guess: ";
    cin >> guess;
    cout << "Possible root of the equation is : " << newtonRaphson(guess, a, b, c, d, e);
    */
    return 0;
}