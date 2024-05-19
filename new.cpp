#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream fin("test.txt");
    string str;

    // READING
    // M1 -> takes output till first space( ) or new line(\n) in the file
    // fin>>str;
    // cout<<str;
    
    // M2 -> takes output till getline returns a value
    // while (getline(fin,str))
    // {
    //     cout<<str<<endl;
    // }

    // WRITING
    // M1 -> overwrites till first space or new line in str
    // cout<<"Enter message: ";
    // cin>>str;
    // fin<<str;

    cout<<"Enter message: ";
    gets(str);
    while (getline(fin,str))
    {
        /* code */
    }
    
   
    fin.close();
    return 0;
}