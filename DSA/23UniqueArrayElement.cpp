#include <iostream>
using namespace std;
/*
    3 1 4 3 4
    3 -> 0011
    1 -> 0001
    4 -> 0100
    3 -> 0011
    4 -> 0100

    3 xor 1 -> 0010 xor 4 -> 0110 xor 3 -> 0101 xor 4 -> 0001
    
*/
int findUnique(int *arr, int size)
{
    int start = *arr;
    for (int i = 1 ; i < size ; i++ ){
        start ^= *(arr+i);
    }
    return start;
}
int main() {
    int arr[5] = {3,1,4,3,4};
    cout<<"UNIQUE : "<<findUnique(arr,5)<<endl;
    return 0;
}