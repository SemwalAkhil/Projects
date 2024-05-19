// 7. Write a C++ program to append new data to an existing text file.
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    fstream fobj;
    fobj.open("newText.txt",ios::app);
    fobj<<"hello world"<<endl;
    fobj.close();
    return 0;
}