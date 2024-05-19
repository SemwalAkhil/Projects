// 13.	WAP to show the use of  Inline function
#include <iostream>
using namespace std;
void inline swap(int& x,int& y){ int temp = x; x = y; y = temp;}
int main() {
    int x,y;
    cout<<"ENTER NUMBER X : ";
    cin>>x;
    cout<<"ENTER NUMBER Y : ";
    cin>>y;
    cout<<"X : "<<x<<" Y : "<<y<<endl;
    swap(x,y);
    cout<<"X : "<<x<<" Y : "<<y<<endl;
    return 0;
}