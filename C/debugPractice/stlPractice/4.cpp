// 4. Program to perform Deep Copy for String?
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    string str2;
    printf("Enter string");
    cin >> str1;
    str2 = str1;
    printf("%s %p %s %p", str1.c_str(), &str1, str2.c_str(), &str2);
}