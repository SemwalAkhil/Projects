// 7.	WAP to show the use of Reference variable.
#include <iostream>
using namespace std;
int main() {
    int object;
    cout<<"ENTER A NUMBER : ";
    cin>>object;
    int &reference = object;
    int nonReference = object;
    
    cout<<"-------------------------------------------------------------"<<endl;
    // original values
    cout<<"REFERENCE :"<<reference<<endl;
    cout<<"OBJECT :"<<object<<endl;
    cout<<"NON REFERENCE :"<<nonReference<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    
    cout<<"REFERENCE--"<<endl;
    reference--;
    cout<<"-------------------------------------------------------------"<<endl;
    
    // after modification to reference 
    cout<<"REFERENCE :"<<reference<<endl;
    cout<<"OBJECT :"<<object<<endl;
    cout<<"NON REFERENCE :"<<nonReference<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    
    cout<<"OBJECT++"<<endl;
    object++;
    cout<<"-------------------------------------------------------------"<<endl;

    // after modification to object
    cout<<"REFERENCE :"<<reference<<endl;
    cout<<"OBJECT :"<<object<<endl;
    cout<<"NON REFERENCE :"<<nonReference<<endl;
    cout<<"-------------------------------------------------------------"<<endl;

    cout<<"NON REFERENCE--"<<endl;
    nonReference--;
    cout<<"-------------------------------------------------------------"<<endl;
    
    // after modification to non refernce
    cout<<"REFERENCE :"<<reference<<endl;
    cout<<"OBJECT :"<<object<<endl;
    cout<<"NON REFERENCE :"<<nonReference<<endl;
    
    return 0;
}