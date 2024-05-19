#include <iostream>
using namespace std;
/*
    -> 1 , 2 , 3 , 4 , 5
    -> 2 , 1 , 4 , 3 , 5 
*/
void swapAlt(int arr[],int size){
    int temp = 0;
    for (int i = 0; i < (size-1); i++)
    {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        i++;
    }
}
void print(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    print(arr,9);
    swapAlt(arr,9);
    print(arr,9);
    return 0;
}