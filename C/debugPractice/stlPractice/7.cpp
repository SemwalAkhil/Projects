// 7. Program to check whether a string is a Palindrome
// 13. Program to determine whether a given string is palindrome
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPallindrome(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}
int main()
{
    string str;
    printf("Enter string : ");
    cin >> str;
    printf("%s", isPallindrome(str) ? "Pallindrome" : "Not Pallindrome");
}