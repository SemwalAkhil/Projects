#include <iostream>
using namespace std;
/*
 1 1 2 2 3 4 4
 1 ^ 1 -> 01 ^ 01 -> 00
 0 ^ 2 -> 00 ^ 10 -> 10
 2 ^ 2 -> 10 ^ 10 -> 00
 0 ^ 3 -> 00 ^ 11 -> 11
 3 ^ 4 -> 011 ^ 100 -> 111
 7 ^ 4 -> 111 ^ 100 -> 011

 XOR -> n^n = 0 0^n = n
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
    // int arr[] = {1,1,2,2,3,4,4};
    int arr[] = {1,2,3,4,1,2,4};
    cout<<findUnique(arr,7)<<endl;
    return 0;
}