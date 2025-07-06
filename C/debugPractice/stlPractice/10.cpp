// 10. Program to count the total number of characters in a string
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    printf("Enter string : ");
    getline(cin, str);
    printf("No. of chars : %d", str.length());
}