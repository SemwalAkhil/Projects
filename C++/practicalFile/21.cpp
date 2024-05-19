// 21.	WAP for array of objects.
#include <iostream>
using namespace std;
class Solution{
    int id;
    public:
    void setId(){
        cout<<"ENTER ID : ";
        cin>>id;
    }
    void getId(){
        cout<<"ID : "<<id<<endl;
    }

};
int main() {
    // METHOD 1 -> hard coded
    Solution a,b,c,d,e;
    Solution arr1[] = {a,b,c,d,e};
    for (int i = 0; i < 5; i++)
    {
        arr1[i].setId();
    }
    for (int i = 0; i < 5; i++)
    {
        arr1[i].getId();
    }
    // METHOD 2 -> dynamic allocation
    cout<<"------------------------------------------------------"<<endl;
    int size;
    cout<<"ENTER ARRAY SIZE : ";
    cin>>size;
    Solution* arr2 = new Solution[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i].setId();
    }
    for (int i = 0; i < size; i++)
    {
        arr2[i].getId();
    }
    delete[] arr2;
    return 0;
}