#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> lst1 = {1,2,3,4,5};
    cout<<"List 1 : ";
    for (auto i = lst1.begin() ; i != lst1.end() ; i++)
    {
        cout<< *i <<" ";
    }
    cout<<endl;
    
    return 0;
}