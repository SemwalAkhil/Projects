// 3. Write a C++ program to count the number of lines in a text file.
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
        cout<<"File content"<<endl;
        while (getline(fobj,line))
        {
            count++;
            cout<<line<<endl;
        }
        cout<<"Number of lines : "<<count<<endl;
    }
    else{
        cout<<"Error opening file"<<endl;
    }
    
    return 0;
}
