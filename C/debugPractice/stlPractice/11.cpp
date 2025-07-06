// 11. Program to count the total number of punctuation characters exists in a String
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int countPunc(string str)
{
    int count = 0;
    for (auto &&i : str)
    {
        if (ispunct(static_cast<unsigned char>(i)))
        {
            ++count;
        }
    }
    return count;
}
int main()
{
    string str;
    printf("Enter string : ");
    getline(cin, str);
    printf("No. of punctuations : %d", countPunc(str));
}