// 12. Program to count the total number of vowels and consonants in a string
#include <string>
#include <iostream>
#include <cctype>
#include <utility>
using namespace std;
pair<int, int> countVowelsConsonant(string str)
{
    int mychar, vcount = 0, ccount = 0;
    for (auto &&i : str)
    {
        if (isalpha(static_cast<unsigned char>(i)))
        {
            mychar = tolower(static_cast<unsigned char>(i));
            if (mychar == 'a' || mychar == 'e' || mychar == 'i' || mychar == 'o' || mychar == 'u')
            {
                ++vcount;
            }
            else
            {
                ++ccount;
            }
        }
    }
    return pair<int, int>(vcount, ccount);
}
int main()
{
    string str;
    printf("Enter string : ");
    getline(cin, str);
    pair<int, int> count = countVowelsConsonant(str);
    printf("No. of vowels : %d consonants : %d", count.first, count.second);
}