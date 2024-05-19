// 4. Write a C++ program to count the number of words in a text file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream fobj;
    fobj.open("newText.txt");
    if (fobj){
        string line;
        int count = 0;
        while (fobj>>line)
        {
            count++;
        }
        cout<<"Number of words : "<<count<<endl;
    }
    else{
        cout<<"Error opening file"<<endl;
    }
    
    return 0;
}