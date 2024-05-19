#include <iostream>
using namespace std;
int linearSearch(int arr[],int size,int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
    
}
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int ind = linearSearch(arr,10,11);
    if (ind >= 0)
    {
        cout<<"10 AT INDEX : "<<ind<<endl;
    }
    else
    {
        cout<<"ERROR IN FETCHING ELEMENT"<<endl;
    }
    
    
    return 0;
}