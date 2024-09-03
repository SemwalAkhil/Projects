#include <iostream>
using namespace std;

pair<float, int> converter(float num)
{
    pair<float, int> myNum = {num, 0};
    while (int(myNum.first) != 0)
    {
        myNum.first /= 10;
        myNum.second += 1;
    }
    return myNum;
}
pair<float, int> subtracter(float first, float second)
{
    pair<float, int> p1 = converter(first);
    pair<float, int> p2 = converter(second);
    while (p1.second != p2.second)
    {
        if (p1.second < p2.second)
        {
            p1.first /= 10;
            p1.second += 1;
        }
        else
        {
            p2.first /= 10;
            p2.second += 1;
        }
    }
    p1.first -= p2.first;
    return p1;
}
int main()
{
    float first = 1356.57f;
    float second = 123.45f;
    pair<float, int> res = subtracter(first, second);
    cout << first << " - " << second << " = " << res.first << "E" << res.second << endl;
}