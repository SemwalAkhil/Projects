// 6. Write a C++ program to find and replace a specific word in a text file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool replace(string sfind,string sreplace,string fileName){
    fstream robj,wobj;
    robj.open(fileName,ios::in);
    wobj.open("temp.txt",ios::out);
    if (!robj){
        return false;
    }
    string line;
    while (getline(robj,line))
    {
        if (line.find(sfind) >= 0 && line.find(sfind) < line.size())
        {
            line.replace(line.find(sfind),sfind.length(),sreplace);
        } 
        wobj<<line<<endl;
    }
    robj.close();
    wobj.close();
    wobj.open(fileName,ios::out);
    robj.open("temp.txt",ios::in);
    while (getline(robj,line))
    {
        wobj<<line<<endl;
    }
    robj.close();
    wobj.close();
    remove("temp.txt");
    return true;
}
void displayContent(string filename){
    ifstream fobj;
    fobj.open(filename);
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
    fobj.close();
}
int main() {
    displayContent("newText.txt");
    if (replace("world","universe","newText.txt")){
        cout<<"Replaced successfully"<<endl;
    }
    else{
        cout<<"Replace failed"<<endl;
    }
    displayContent("newText.txt");
    
    return 0;
}