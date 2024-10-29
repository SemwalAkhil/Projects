// 9. Gauss Elimination
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
    void set(double a, double b, double c, double d)
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
void gaussElim(equation eq1, equation eq2, equation eq3)
{
    // X ELimination
    eq2 = eq2 - ((eq1 / eq1.a) * (eq2.a)); // remove x from eq 2 by making coeff 0
    eq3 = eq3 - ((eq1 / eq1.a) * (eq3.a)); // remove x from eq 3 by making coeff 0

    // Y Elimination
    eq3 = eq3 - ((eq2 / eq2.b) * (eq3.b)); // remove y from eq 3 by making coeff 0

    // Z Value
    eq3 = eq3 / eq3.c; // removing coeff of z

    // Y Value
    eq2 = eq2 / (eq2.b);    // removing coeff of y
    eq2.d -= eq2.c * eq3.d; // subtracting cz from d
    // X Value
    eq1 = eq1 / eq1.a;                          // removing coeff of x
    eq1.d -= (eq1.b * eq2.d) + (eq1.c * eq3.d); // subtracting (by + cz) from d
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
    gaussElim(equations[0], equations[1], equations[2]);
    return 0;
}