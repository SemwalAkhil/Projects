// 8. Birge Vietta
#include <iostream>
#include <cmath>
#include <stdarg.h>
using namespace std;

double function(double x, double coeffs[])
{
    return (coeffs[0] * pow(x, 4) + coeffs[1] * pow(x, 3) + coeffs[2] * pow(x, 2) + coeffs[3] * x + coeffs[4]);
}
double birgeVietta(double guess, double coeffs[], double tolerance = 0.002)
{
    double arrB[5] = {coeffs[0]};
    double arrC[5] = {coeffs[0]};
    double app;
    for (int i = 1; i < 5; i++)
    {
        arrB[i] = coeffs[i] - arrB[i-1]* guess;
    }
    for (int i = 1; i < 5; i++)
    {
        arrC[i] = arrB[i - 1] * guess;
    }
    app = guess - (arrB[4] / arrC[3]);
    cout << arrB[0] << " " << arrB[1] << " " << arrB[2] << " " << arrB[3] << " " << arrB[4] << endl;
    cout << arrC[0] << " " << arrC[1] << " " << arrC[2] << " " << arrC[3] << " " << arrC[4] << endl;
    cout << "App = " << app << "  Guess = " << guess << endl;
    if (abs(app - guess) > tolerance)
    {
        return birgeVietta(app, coeffs, tolerance);
    }
    return app;
}
int main()
{
    double coeffs[5], tolerance = 0.002, guess;
    cout << "Enter coefficient of x^4 : ";
    cin >> coeffs[0];
    cout << "Enter coefficient of x^3 : ";
    cin >> coeffs[1];
    cout << "Enter coefficient of x^2 : ";
    cin >> coeffs[2];
    cout << "Enter coefficient of x : ";
    cin >> coeffs[3];
    cout << "Enter constant : ";
    cin >> coeffs[4];
    // Taking lower and upper bounds from user

    cout << "Give an initial guess: ";
    cin >> guess;
    cout << "Possible root of the equation is : " << birgeVietta(guess, coeffs);

    return 0;
}