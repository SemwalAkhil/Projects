// 18.	WAP to show the use of private functions of class.
#include <iostream>
using namespace std;
class Solution{
    private:
        int a,b;
        int sum(){
            return a+b;
        }
    public:
        int resultVar;
        void set(int x, int y){
            a = x;
            b = y; 
        }
        void resultFunc(){
            resultVar = sum();
            cout<<resultVar<<endl;
        }
};
int main() {
    Solution a;
    int x,y;
    
    cout<<"ENTER NUMBER 1 : ";
    cin>>x;
    cout<<"ENTER NUMBER 2 : ";
    cin>>y;

    a.set(x,y);

    // cout<<"A : "<<a<<endl; // trying to access private member -> error
    // cout<<"SUM : "<<a.sum()<<endl; // trying to access private member function -> error
    
    a.resultFunc();
    cout<<"RESULT : "<<a.resultVar<<endl;
    return 0;
}