// 3. Program to Check if a String contains only digits ?
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool checkNum(string str)
{
    for (auto &&i : str)
    {
        if (!isdigit(static_cast<unsigned char>(i)))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    printf("Enter str : ");
    cin >> str;
    printf("number ? : %s", (checkNum(str) ? "Yes" : "No"));
}