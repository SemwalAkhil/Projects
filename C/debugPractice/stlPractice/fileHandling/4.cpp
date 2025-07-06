// 4. Write a C++ program to count the number of words in a text file.
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream myfile("newFile.txt", ios::in);
    string word;
    int count = 0;
    while (myfile >> word)
    {
        ++count;
    }
    printf("No. of words: %d", count);
}