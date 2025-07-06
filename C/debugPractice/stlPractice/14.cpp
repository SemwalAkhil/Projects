// 14. Program to determine whether one string is a rotation of another
#include <iostream>
#include <string>
using namespace std;
bool isRotation(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    string newStr = str1 + str1;
    return newStr.find(str2) != string::npos;
}
int main()
{
    string str1, str2;
    printf("Enter string 1 : ");
    getline(cin, str1);
    printf("Enter string 2 : ");
    getline(cin, str2);
    printf("%s is %s of %s", str1.c_str(), isRotation(str1, str2) ? "is rotation" : "is not rotation", str2.c_str());
}