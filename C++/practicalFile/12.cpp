// 12.	WAP to find the maximum of ten integer values stored in array. Pass array to function and return maximum value by using reference.
#include <iostream>
using namespace std;
int& max(int arr[],int len){
    int maxInd = 0;
    for (int i = 0; i < len  ; i++)
    {
        if (arr[i] > arr[maxInd]){
            maxInd = i;
        }
    }
    return arr[maxInd];
    
}
int main() {
    // get array length
    int len;
    cout<<"ENTER ARRAY LENGTH : ";
    cin>>len;
    if (len > 10)
    {
        cout<<"MAXIMUM POSSIBLE LENGTH = 10 !!!"<<endl;
        cout<<"SETTING LENGTH TO 10"<<endl;
        len = 10;
    }
    // allocating memory to array
    int* arr = new int[len];
    // getting array elements
    for (int i = 0 ; i < len ; i++){
        cout<<"ENTER ARRAY ELEMENT :";
        cin>>arr[i];
    }
    cout<<"---------------------------------------------------------------"<<endl;
    
    // getting reference to max value of array
    int& maxVal = max(arr,len);
    cout<<"MAX VALUE IS : "<<maxVal<<endl;
    // since reference is being returned so address of returned value points to array element
    cout<<"ADDRESS MAX VALUE : "<<&maxVal<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    
    for (int i = 0; i < len; i++)
    {
        cout<<"ADDRESS ARRAY ELEMENT : "<<&arr[i]<<endl;
    }
    
    // deallocating memory
    delete[] arr;
    return 0;
}