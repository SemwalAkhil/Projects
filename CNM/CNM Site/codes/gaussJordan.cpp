#include <iostream>
using namespace std;
class equation
{
public:
    double a, b, c, d;
    equation()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->d = 0;
    }
    equation(double a, double b, double c, double d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    set(double a, double b, double c, double d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    equation operator/(double val)
    {
        equation temp(this->a, this->b, this->c, this->d);
        temp.a /= val;
        temp.b /= val;
        temp.c /= val;
        temp.d /= val;
        return temp;
    }
    equation operator-(equation eq)
    {
        equation temp(this->a, this->b, this->c, this->d);
        temp.a -= eq.a;
        temp.b -= eq.b;
        temp.c -= eq.c;
        temp.d -= eq.d;
        return temp;
    }
    equation operator*(double val)
    {
        equation temp(this->a, this->b, this->c, this->d);
        temp.a *= val;
        temp.b *= val;
        temp.c *= val;
        temp.d *= val;
        return temp;
    }
    friend ostream &operator<<(ostream &, equation);
    ~equation() {}
};
ostream &operator<<(ostream &os, equation eq)
{
    os << eq.a << "x + " << eq.b << "y + " << eq.c << "z = " << eq.d << "\n";
    return os;
}
void gaussJordan(equation eq1, equation eq2, equation eq3)
{
    // X
    eq1 = eq1 / eq1.a;           // setting coeff of x1 1
    eq2 = eq2 - (eq1 * (eq2.a)); // setting coeff of x2 0
    eq3 = eq3 - (eq1 * (eq3.a)); // setting coeff of x3 0

    // Y
    eq2 = eq2 / eq2.b;           // setting coeff of y1 0
    eq1 = eq1 - (eq2 * (eq1.b)); // setting coeff of y2 1
    eq3 = eq3 - (eq2 * (eq3.b)); // setting coeff of y3 0

    // Z
    eq3 = eq3 / eq3.c;           // setting coeff of z1 0
    eq1 = eq1 - (eq3 * (eq1.c)); // setting coeff of z2 0
    eq2 = eq2 - (eq3 * (eq2.c)); // setting coeff of z3 1

    cout << "x = " << eq1.d << " y = " << eq2.d << " z = " << eq3.d << endl;
}
int main()
{
    double a, b, c, d;
    equation equations[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Equation " << i + 1 << " a b c d : ";
        cin >> a >> b >> c >> d;
        equations[i].set(a, b, c, d);
    }
    gaussJordan(equations[0], equations[1], equations[2]);
    return 0;
}