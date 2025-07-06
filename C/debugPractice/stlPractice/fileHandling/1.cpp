// 1. Write a C++ program to create a new text file and write some text into it.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file("newFile.txt", ios::out);
    if (!file.is_open())
    {
        printf("Failed to open file");
        return 1;
    }
    string str = "Hello World";
    file.write(str.c_str(), str.size());
    file.close();
    return 0;
}