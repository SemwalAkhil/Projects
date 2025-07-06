// 1. Program to Check Anagram

// Explanation -

// Two Strings are called the anagram if they contain the same characters. However, the order or sequence of the characters can be different.
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

bool anagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}
int main()
{
    string str1, str2;
    cout << "Enter string1 : ";
    cin >> str1;
    cout << "Enter string2 : ";
    cin >> str2;
    cout << "Anagram ? " << (anagram(str1, str2) ? "True" : "False") << endl;
}