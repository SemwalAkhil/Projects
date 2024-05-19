// 1. Write a C++ program to create a new text file and write some text into it.
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream fobj;
    fobj.open("newText.txt");
    fobj.write("hello world",11);
    fobj.close();
    return 0;
}
