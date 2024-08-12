#include <iostream>
#include <vector>
using namespace std;
void reverseArray(vector<int> &arr , int m) {
    // Write your code here.
    if (arr.size() > 1){
        auto beg = arr.begin() + m + 1;
        auto end = arr.end() - 1;
        while (beg < end){
            swap(*beg,*end);
            beg++;
            end--;
        }
    }
}
// ALT APPROACH
void reverseArray2(vector<int> &arr , int m) {
    // Write your code here.
    int beg = m+1;
    int end = arr.size() - 1;
    while (beg < end){
        swap(arr[beg],arr[end]);
        beg++;
        end--;
    }
}
void showVec(vector<int>& v){
  cout<<" { ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
      cout<<*i<<" ";
    }
    cout<<"} "<<endl;
}
int main() {
    // vector<int> v = {1,2,3,4,5,6};
    // reverseArray(v,3); 
    // vector<int> v = {5};
    // reverseArray(v,0);
    vector<int> v = {3,4};
    reverseArray(v,0); 
    cout<<"v : ";showVec(v);
    return 0;
}
