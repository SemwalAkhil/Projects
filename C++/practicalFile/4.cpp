// 4.	WAP to generate the Prime number up to a given number N.
#include <iostream>
#include <cmath>
using namespace std;
class Solution{
    public:
    void primeSOE(int n){
        // creating an array of bool
        bool *arr = new bool[n+1];
        for (int i = 2; i <= n; i++)
        {
            arr[i] = true;
        }
        // setting the composites false
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (arr[i]){
                for (int j = i*i; j <= n; j+=i){
                    arr[j] = false;
                }
            }     
        }
        // displaying array of primes
        cout<<"[";
        for (int i = 2; i <= n; i++)
        {
            if (arr[i]){
                cout<<i<<" ";
            }
        }
        cout<<"]";
        // deallocating memory
        delete[] arr;
    }
};
int main() {
    Solution a;
    int num = 0;
    cout<<"PRIME NUMBER UPTO : ";
    cin>>num;
    a.primeSOE(num);  
    return 0;
}