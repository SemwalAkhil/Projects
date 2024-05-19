#include <iostream>
using namespace std;
int main() {
    int a = 2;
    int b = 3;
    cout<<"A : "<<a<<" B : "<<b<<endl;
    int c;
    // AND
    cout<<"AND"<<endl;
    c = a&b;
    /*
        x y   z
        0 0   0
        0 1   0
        1 0   0
        1 1   1

        2 -> 10
        3 -> 11
        c -> 10
    */
    /*
      odd & 1 -> 1
      even & 1 -> 0
    */
    cout<<c<<endl;
    // OR
    cout<<"OR"<<endl;
    c = a|b;
    /*
        x y   z
        0 0   0
        0 1   1
        1 0   1
        1 1   1

        2 -> 10
        3 -> 11
        c -> 11
    */
    cout<<c<<endl;
    // XOR
    cout<<"XOR"<<endl;
    c = a^b;
    /*
        x y   z
        0 0   0
        0 1   1
        1 0   1
        1 1   0

        2 -> 10
        3 -> 11
        c -> 01
    */
    cout<<c<<endl;
    // NOT
    cout<<"NOT"<<endl;
    c = ~a;
    /*
        x   z
        1   0
        0   1

        2 -> 0000000 ... 10 -> since 4 byte int 
          -> 1111111 ... 01 -> not of 2
          -> since first digit 1 hence negative number
          -> 0000000 ... 10 -> 1's complement
          -> 0000000 ... 11 -> 2's complement                  
        c -> -3
    */
    cout<<c<<endl;
    c = ~b;
    /*
        3 -> 0000000 ... 11 -> since 4 byte int 
          -> 1111111 ... 00 -> not of 2
          -> since first digit 1 hence negative number
          -> 0000000 ... 11 -> 1's complement
          -> 000000 ... 100 -> 2's complement                  
        c -> -4
    */
    cout<<c<<endl;
    // LEFT SHIFT
    cout<<"LEFT SHIFT"<<endl;
    a = 2;
    c = a<<1;
    /*
        2 -> 0000000 ... 10 -> since 4 byte int                
          -> 000000 ... 100
        c -> 4
        FOR POSITIVE NUMBER EMPTY SPACES / PADDING IS FILLED BY 0
        FOR NEGATIVE NUMBER IT IS COMPILER DEPENDANT 
    */
    cout<<c<<endl;
    a = -2;
    c = a<<1;
    /*
        2 -> 0000000 ... 10 -> since 4 byte int  
          -> 1111111 ... 01 -> 1's complement
          -> 1111111 ... 10 -> 2's complement
          -> 111111 ... 100 -> left shift
          -> 000000 ... 011 -> 1's complement
          -> 000000 ... 100 -> 2's complent
        c -> -4
        FOR POSITIVE NUMBER EMPTY SPACES / PADDING IS FILLED BY 0
        FOR NEGATIVE NUMBER IT IS COMPILER DEPENDANT 
    */
    cout<<c<<endl;
    a = 2; 
    c = a<<2;
    /*
        2 -> 0000000 ... 10 -> since 4 byte int                
          -> 00000 ... 1000
        c -> 8
    */
    cout<<c<<endl;
    // RIGHT SHIFT
    cout<<"RIGHT SHIFT"<<endl;
    c = a>>1;
    /*
        2 -> 0000000 ... 10 -> since 4 byte int                
          -> 0000000 ... 01
        c -> 1
    */
    cout<<c<<endl;
    c = a>>2;
    /*
        2 -> 0000000 ... 10 -> since 4 byte int                
          -> 0000000 ... 00
        c -> 0
    */
    cout<<c<<endl;
    return 0;
}