#include <iostream>
#include <algorithm>
using namespace std;
void traverse(int arr[]){
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
int main() {
    // int arr[10] = 1; // ERROR
    int arr2[10] = {1}; // FIRST ELEMENT 1 ALL OTHER 0
    int arr3[10]; // ALL ELEMENT GARBAGE VALUE
    int arr4[10];
    fill(arr4, arr4 + 10, 10); // ALL ELEMENTS TO 10

    // traverse(arr);
    cout<<"\narr2\n"<<endl;
    traverse(arr2);
    cout<<"\narr3\n"<<endl;
    traverse(arr3);
    cout<<"\narr4\n"<<endl;
    traverse(arr4);
    return 0;
}