// 19.	WAP to implement array within class.
#include <iostream>
using namespace std;
class Solution{
    int* arr;
    int size;
    public:
    void allocateArray(){
        cout<<"ENTER SIZE OF ARRAY : ";
        cin>>size;
        arr = new int[size];
    }
    void initialiseArray(){
        for (int i = 0; i < size; i++)
        {
            cout<<"ENTER ARRAY ELEMENT : ";
            cin>>arr[i]; 
        }
    }
    void displayArray(){
        cout<<"{ ";
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" "; 
        }
        cout<<"}";
    }
};
int main() {
    Solution a;
    a.allocateArray();
    a.initialiseArray();
    a.displayArray();
    return 0;
}