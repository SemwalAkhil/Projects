#include <iostream>
#include <fstream>
using namespace std;

int main(){
    /*
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
        // code
    }
    
   
    fin.close();
    return 0;
    */
//    int n;
//    if (cin>>n){cout<<"hello world";}

    int a = 5;
    cout<<++a*a++<<endl; // 6 7 -> Output : 42
    a = 5;
    cout<<a++*++a<<endl; // 5 7 -> Output : 35
    a = 5;
    cout<<a++<<++a<<endl; // 6 7 -> Output : 67
    a = 5;
    cout<<++a<<a++<<endl; // 7 5 -> Output : 75
    a = 5;
    cout<<a++<<a<<endl;
    a = 5;
    cout<<++a<<a<<endl; 
    a = 5;
    cout<<(++a)*(a++)<<endl;
    a=-28; 
    a=a>>1;
    cout<<a;
}
