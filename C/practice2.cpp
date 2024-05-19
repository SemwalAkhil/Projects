#include <iostream>
using namespace std;

void input(int &num){
    cout<<"Enter value : ";
    cin>>num;
    num++;
}
void input(char &num){
    cout<<"Enter value : ";
    cin>>num;
    num+=10;
}
int main() {
    int num;
    char alpha;
    input(num);
    cout<<"Number is : "<<num<<endl;
    input(alpha);
    cout<<"Number is : "<<alpha<<endl;
    return 0;
}