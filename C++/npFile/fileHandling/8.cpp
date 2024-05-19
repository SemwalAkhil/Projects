// 8. Write a C++ program to sort the lines of a text file in alphabetical order.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string sortString(string str) {
  for (int i = 0; i < str.length() - 1; i++) { // Outer loop: 0 to str.length() - 2
    for (int j = i + 1; j < str.length(); j++) { // Inner loop: i + 1 to str.length() - 1
      if (str[j] > str[j + 1]) {  // Lexicographic comparison (avoids type conversion)
        char temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
      }
    }
  }
  return str;
}
bool sort(string fileName){
    fstream robj,wobj;
    robj.open(fileName,ios::in);
    wobj.open("temp.txt",ios::out);
    if (!robj){
        return false;
    }
    string line;
    while (getline(robj,line))
    {
        cout<<"line : "<<line<<endl;
        line = sortString(line);
        cout<<"line : "<<line<<endl;
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
    // displayContent("newText.txt");
    // if (sort("newText.txt")){
    //     cout<<"Sorted successfully"<<endl;
    // }
    // else{
    //     cout<<"Sort failed"<<endl;
    // }
    // displayContent("newText.txt");
    cout<<sortString("abcd");
    return 0;
}