// 2. Write a C++ program to open an existing text file and display its contents on the console.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream myfile("newFile.txt", ios::in);
    if (!myfile.is_open())
    {
        printf("Failed to open the file");
        return 1;
    }

    string line;
    while (getline(myfile, line))
    {
        printf("%s\n", line.c_str());
    }
    myfile.close();
    return 0;
}