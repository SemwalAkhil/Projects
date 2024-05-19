#include <iostream>
using namespace std;
/*
    a -> 2 -> 10
    b -> 3 -> 11
    setbits-> 3
*/
int setBits(int num){
    int count = 0;
    while (num != 0){
        if (num & 1)
        {
            count++;
        }
        num = num>>1;
    }
    return count;
}
int main() {
    int a = 10,b = 25;
    int counta = setBits(a), countb = setBits(b);
    cout<<"TOTAL SETBITS : "<<counta+countb<<endl;
    return 0;
}