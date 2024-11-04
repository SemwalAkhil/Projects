// 23. Modified Euler's Method
#include <iostream>
#include <iomanip>

using namespace std;

// Function defining the differential equation dy/dx = f(x, y)
double f(double x, double y)
{
    return x + y; // Example: dy/dx = x + y
}

// Function to perform Modified Euler's Method
void modifiedEulerMethod(double x0, double y0, double xEnd, double h)
{
    double x = x0;
    double y = y0;

    cout << "x" << setw(15) << "y" << endl;
    cout << "-------------------------" << endl;
    while (x <= xEnd)
    {
        cout << fixed << setprecision(4) << x << setw(15) << y << endl;

        // Predictor step
        double y_predict = y + h * f(x, y);

        // Corrector step
        y = y + (h / 2) * (f(x, y) + f(x + h, y_predict));

        // Update x to the next step
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

    // Call Modified Euler's method
    modifiedEulerMethod(x0, y0, xEnd, h);

    return 0;
}
