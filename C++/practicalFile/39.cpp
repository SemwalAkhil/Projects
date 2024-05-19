// 39.	WAP to implement unary operator overloading.
#include <iostream>
using namespace std;
class Solution{
    int data;
    public:
    Solution(){
        cout<<"ENTER DATA : ";
        cin>>data;
    }
    void operator--(){
        data -= 1;
    }
    void operator++(){
        data += 1;
    }
    // dummy int used to implement postfix unarys
    void operator--(int){
        data -= 1;
    }
    void operator++(int){
        data += 1;
    }
    void operator-(){
        data *= -1;
    }
    void operator+(){
        data *= 1;
    }
    void display(){
        cout<<"DATA : "<<data<<endl;
    }
};
int main() {
    Solution a;
    a.display();
    --a;
    cout<<"--a"<<endl;
    a.display();
    ++a;
    cout<<"++a"<<endl;
    a.display();
    a--;
    cout<<"a--"<<endl;
    a.display();
    a++;
    cout<<"a++"<<endl;
    a.display();
    -a;
    cout<<"-a"<<endl;
    a.display();
    +a;
    cout<<"+a"<<endl;
    a.display();
    return 0;
}