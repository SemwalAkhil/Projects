#include <iostream>
using namespace std;
int main() {
    int n=5;
    int pos=2;
    int BitMask=1<<pos;

    cout<<"n : "<<n<<endl;
    cout<<"BitMask : "<<BitMask<<endl;
    cout<<"BitMask & n : "<<(BitMask & n)<<endl;
    cout<<"((BitMask & n) == 0) : "<<((BitMask & n) == 0)<<endl;
    if((BitMask & n) == 0){
        cout<<"ZERO"<<endl;
    }
    else{
        cout<<"ONE"<<endl;
    }
    return 0;
}