// 3. Write a C++ program to count the number of lines in a text file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream myfile("newFile.txt", ios::in);
    if (!myfile.is_open())
    {
        printf("Failed to open file");
        return 1;
    }
    string line;
    int count = 0;
    while (getline(myfile, line))
    {
        ++count;
    }
    printf("no. of lines in the file : %d", count);
    myfile.close();
    return 0;
}