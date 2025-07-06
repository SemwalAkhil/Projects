// 6. Program to Add Characters to a String
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    char ch;
    printf("Enter string : ");
    getline(cin, str);
    printf("Enter character : ");
    cin >> ch;
    str.push_back(ch);
    printf("New str : %s", str.c_str());
}