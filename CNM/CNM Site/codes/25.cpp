// 25.Chebyshev Polynomials
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate Chebyshev polynomials of the first kind
double chebyshevPolynomial(int n, double x)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    // Initialize T_0(x) and T_1(x)
    double T0 = 1;
    double T1 = x;
    double Tn;

    // Use the recursive relation to calculate T_n(x)
    for (int i = 2; i <= n; ++i)
    {
        Tn = 2 * x * T1 - T0;
        T0 = T1;
        T1 = Tn;
    }

    return Tn;
}

int main()
{
    int degree;
    double x;

    // Input the degree of the polynomial and the point x
    cout << "Enter the degree of Chebyshev polynomial (n): ";
    cin >> degree;
    cout << "Enter the value of x: ";
    cin >> x;

    // Calculate and display Chebyshev polynomials from T_0(x) to T_n(x)
    cout << fixed << setprecision(4);
    cout << "Chebyshev Polynomials of the First Kind at x = " << x << ":\n";
    for (int i = 0; i <= degree; ++i)
    {
        double Tn = chebyshevPolynomial(i, x);
        cout << "T_" << i << "(" << x << ") = " << Tn << endl;
    }

    return 0;
}
