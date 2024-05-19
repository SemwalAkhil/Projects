#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
/*
    -4 -> 4 -> 000000...100
            -> 111111...011  ^ 0000...001
            -> 111111...010
            -> 111111...100
*/
int main() {
    int num = -4,power = 0;
    string answer = "";
    unsigned int uNum = (unsigned int)num;
    cout<<uNum<<endl;
    do{    
        if (uNum&1){
            answer.insert(0,"1");
        }
        else{
            answer.insert(0,"0");
        }
        uNum = uNum>>1;                                   
        power++;
        
    }while(uNum!=0);
    cout<<"BINARY REPRESENTATION : "<<answer<<endl;
    return 0;
}