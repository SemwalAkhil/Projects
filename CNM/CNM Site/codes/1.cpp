// 1. Binary to decimal and vice versa
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
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
void bin1Complement(string &bin)
{
    for (auto it = bin.begin(); it != bin.end(); it++)
    {
        *it = (*it == '0') ? '1' : '0';
    }
}
void bin2Complement(string &bin)
{
    bin1Complement(bin);
    int carry = 1;
    auto chr = bin.end();
    while (carry != 0)
    {
        if (*chr == '0')
        {
            *chr = '1';
            carry = 0;
        }
        else
        {
            *chr = '0';
            chr--;
        }
    }
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
            ret += ((*it - 48) * pow(2, maxPow)); // 48 is ascii of '0'
            maxPow--;
        }
    }
    return ret;
}
double binaryToDecimalNeg(string &bin)
{
    bin2Complement(bin);
    int maxPow = 6;
    double ret = 0;
    for (auto it = bin.begin() + 1; it != bin.end(); it++)
    {
        ret += ((*it - 48) * pow(2, maxPow));
        maxPow--;
    }
    return ret * (-1);
}
string decimalToBinaryNeg(double num)
{
    int pre = num * (-1);
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
    bin2Complement(bin);
    return bin;
}
string decimalToBinary(double num)
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
    if (post != 0)
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
    string bin;
    double num;
    cout << "Enter a binary string : ";
    cin >> bin;
    cout << binaryToDecimal(bin) << endl;
    cout << "Enter a number : ";
    cin >> num;
    cout << decimalToBinary(num) << endl;
    cout << "Enter a 8 bit negative binary : ";
    cin >> bin;
    cout << binaryToDecimalNeg(bin) << endl;
    cout << "Enter a negative number : ";
    cin >> num;
    cout << setw(8) << setfill('1') << decimalToBinaryNeg(num) << endl;
    return 0;
}
