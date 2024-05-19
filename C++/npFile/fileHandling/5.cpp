// 5. Write a C++ program to copy the contents of one text file to another.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    fstream robj,wobj;
    robj.open("newText.txt",ios::in);
    wobj.open("newText2.txt",ios::out);
    if (robj){
        string line;
        while (getline(robj,line))
        {
            wobj<<line<<endl;
        }
    }
    else{
        cout<<"Error opening file"<<endl;
    }
    robj.close();
    wobj.close();
    return 0;
}