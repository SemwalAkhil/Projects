// 2. Program to Swapping Pair of Characters

// Explanation -

// Enter the string from user and enter the characters that you want to swap with one another
#include <iostream>
#include <string>
using namespace std;
void swap(string &str, char ch1, char ch2)
{
    for (auto &&i : str)
    {
        if (i == ch1)
        {
            i = ch2;
        }
        else if (i == ch2)
        {
            i = ch1;
        }
    }
}
int main()
{
    string str;
    char ch1, ch2;
    printf("Enter string: ");
    cin >> str;
    printf("Swap char 1 : ");
    cin >> ch1;
    printf("Swap char 2 : ");
    cin >> ch2;
    swap(str, ch1, ch2);
    cout << str;
}