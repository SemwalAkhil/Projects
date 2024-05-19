#include <iostream>
using namespace std;
void revArr(int arr[],int size){
    int temp = 0;
    for (int i = 1; i <= (size/2); i++)
    {
        temp = arr[i-1];
        arr[i-1] = arr[size - i];
        arr[size-i] = temp;
    }
}
int main() {
    int arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
    cout<<"MAIN ARRAY"<<endl;
    for (int i = 0; i < 11; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    revArr(arr,11);
    cout<<"REVERSE ARRAY"<<endl;
    for (int i = 0; i < 11; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}