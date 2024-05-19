// 2. Write a C++ program to open an existing text file and display its contents on the console.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream fobj;
    fobj.open("newText.txt");
    if (fobj){
        string line;
        while (getline(fobj,line))
        {
            cout<<line<<endl;
        }
    }
    else{
        cout<<"Error opening file"<<endl;
    }
    
    return 0;
}
