// 9. Program to count number of words in a String ?
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int countWords(string &str)
{
    // std::istringstream is initialized with the input string.​
    istringstream stream(str);
    string word;
    int count = 0;
    // The while loop extracts words from the stream, incrementing the count for each word.
    while (stream >> word)
    {
        ++count;
    }
    return count;
}
int main()
{
    string str;
    printf("Enter string : ");
    getline(cin, str);
    printf("no. of words : %d", countWords(str));
}