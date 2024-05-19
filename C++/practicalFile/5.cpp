// 5.	WAP to generate N Prime numbers.
#include <iostream>
#include <cmath>
using namespace std;
class Solution{
    public:
    void primeTD(int n){
        // creating new array
        int *arr = new int[n];
        int size = 0;
        // while size of array is less than n
        for (int i = 2; size < n; i++){
            bool isPrime = true;
            // checking if current element is multiple of element till square root of current element
            for (int j = 0 ; arr[j] <= sqrt(i) ; j++){
                // if multiple then not prime
                if (i % arr[j] == 0){
                    isPrime = false;
                    break;
                }
            }
            // if prime then array size is incremented
            if (isPrime){
                arr[size] = i;
                size++;
            }
        }
        // displaying array
        cout<<"[";
        for (int i = 0 ; i < size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"]";
        // deallocating memory
        delete[] arr;
    }
        
};
int main() {
    Solution a;
    int num;
    cout<<"NUMBER OF PRIMES NEEDED : ";
    cin>>num;
    a.primeTD(num);
    return 0;
}