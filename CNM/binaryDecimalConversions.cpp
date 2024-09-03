#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int search(string &str, char c)
{
    auto start = str.begin();
    for (auto i = 0; (start + i) != str.end(); i++)
    {
        if (*(start + i) == c)
        {
            return i;
        }
    }
    return -1;
}
double binaryToDecimal(string &bin)
{
    int decPoint = search(bin, '.');
    int maxPow = (decPoint >= 0) ? (decPoint - 1) : (bin.size() - 1);
    double ret = 0;
    for (auto it = bin.begin(); it != bin.end(); it++)
    {
        if (*it != '.')
        {
            ret += ((*it - 48) * pow(2, maxPow));
            maxPow--;
        }
    }
    return ret;
}
string decimalRoBinary(double num)
{
    int pre = (int)num;
    double post = num - pre;
    string bin = "";
    while (pre != 0)
    {
        int temp = pre % 2;
        if (temp)
            bin = "1" + bin;
        else
            bin = "0" + bin;
        pre /= 2;
    }
    bin += ".";
    while ((bin.size() < 17) && post != 0)
    {
        post *= 2;
        int temp = (int)post;
        if (temp)
        {
            bin += "1";
            post -= 1;
        }
        else
        {
            bin += "0";
        }
    }
    return bin;
}
int main()
{
    string bin = "1011011.11110";
    cout << binaryToDecimal(bin) << endl;
    double num = 91.9375;
    cout << decimalRoBinary(num) << endl;
    return 0;
}
