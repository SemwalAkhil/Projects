// 24.Taylor Series
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Function to calculate factorial of a number
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Function to calculate Taylor series for e^x up to n terms
double taylorSeriesExponential(double x, int n)
{
    double sum = 1.0; // Starting with the first term, which is 1 (x^0 / 0!)

    for (int i = 1; i < n; i++)
    {
        sum += (pow(x, i) / factorial(i));
    }
    return sum;
}

int main()
{
    double x;
    int n;

    // Input the value of x and the number of terms in the series
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the number of terms (n): ";
    cin >> n;

    // Calculate and display the Taylor series sum
    double result = taylorSeriesExponential(x, n);
    cout << fixed << setprecision(6) << "The Taylor series approximation of e^" << x << " up to " << n << " terms is: " << result << endl;

    return 0;
}
