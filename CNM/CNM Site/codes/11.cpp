// 11.Gauss Seidel
#include <iostream>
#include <cmath>
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
    double valueX(double y, double z)
    {
        return (d - (b * y) - (c * z)) / a;
    }
    double valueY(double x, double z)
    {
        return (d - (a * x) - (c * z)) / b;
    }
    double valueZ(double x, double y)
    {
        return (d - (b * y) - (a * x)) / c;
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
void gaussSeidel(equation eq1, equation eq2, equation eq3, double tolerance = 0.002)
{
    double x = 0, y = 0, z = 0;
    double xNew = 0, yNew = 0, zNew = 0;
    do
    {
        x = xNew;
        y = yNew;
        z = zNew;
        xNew = eq1.valueX(yNew, zNew);
        yNew = eq2.valueY(xNew, zNew);
        zNew = eq3.valueZ(xNew, yNew);
    } while ((abs(xNew - x) > tolerance) && (abs(yNew - y) > tolerance) && (abs(zNew - z) > tolerance));

    cout << "x = " << xNew << " y = " << yNew << " z = " << zNew << endl;
}
int main()
{
    double a, b, c, d;
    equation equations[3];
    cout << "Equation solver for form ax+by+cz=d\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Equation " << i + 1 << " a b c d : ";
        cin >> a >> b >> c >> d;
        equations[i].set(a, b, c, d);
    }
    gaussSeidel(equations[0], equations[1], equations[2]);
    return 0;
}