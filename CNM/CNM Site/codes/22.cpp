// 22. Euler's Method
#include <iostream>
#include <iomanip>

using namespace std;

// Function that defines the differential equation dy/dx = f(x, y)
double f(double x, double y)
{
    return x * y; // Example: dy/dx = x + y
}

// Function to perform Euler's method
void eulerMethod(double x0, double y0, double xEnd, double h)
{
    double x = x0;
    double y = y0;

    cout << "x" << setw(10) << "y" << endl;
    cout << "-------------------" << endl;
    while (x <= xEnd)
    {
        cout << fixed << setprecision(4) << x << setw(10) << y << endl;

        y = y + h * f(x, y); // Euler formula: y(i+1) = y(i) + h * f(x(i), y(i))
        x = x + h;
    }
}

int main()
{
    double x0, y0, xEnd, h;

    // Input initial conditions
    cout << "Enter initial value of x (x0): ";
    cin >> x0;
    cout << "Enter initial value of y (y0): ";
    cin >> y0;
    cout << "Enter the value of x at which to end (xEnd): ";
    cin >> xEnd;
    cout << "Enter step size (h): ";
    cin >> h;

    // Call the Euler's method
    eulerMethod(x0, y0, xEnd, h);

    return 0;
}
