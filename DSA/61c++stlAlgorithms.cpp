#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool isEven(int x){
    return !(x%2);
}
bool myfunction (int i, int j) {
  return (i==j);
}
void showVec(vector<int>& v){
  cout<<" { ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
      cout<<*i<<" ";
    }
    cout<<"} "<<endl;
}
/// @brief 
/// @return 
int main() {
    /*
    // all_of
    vector<int> v = {1,2,4,6,8};
    if (all_of(v.begin(),v.end(),isEven)){
        cout<<"All even"<<endl;
    } else {
        cout<<"Not all even"<<endl;
    }
    */
    /*
    // any_of
    vector<int> v = {1,3,5,7,8};
    if (any_of(v.begin(),v.end(),isEven)){
        cout<<"Some even"<<endl;
    } else {
        cout<<"No even"<<endl;
    }
    */
    /*
    // none_of
    vector<int> v = {1,3,5,7};
    if (none_of(v.begin(),v.end(),isEven)){
        cout<<"No even"<<endl;
    } else {
        cout<<"Some even"<<endl;
    }
    */
    /*
    // for_each
    vector<int> v = {1,2,3,4,5};
    for_each(v.begin(),v.end(),[](int i){cout<<i<<" ";});
    */
    /*
    // find
    vector<int> v = {1,2,3,4,5};
    auto it = find(v.begin(),v.end(),3);
    cout<<*it<<endl;
    */
    /*
    // find_if
    vector<int> v = {1,2,3,4,5};
    auto it = find_if(v.begin(),v.end(),isEven);
    cout<<*it<<endl;
    */
    /*
    // find_if_not
    vector<int> v = {1,2,3,4,5};
    auto it = find_if_not(v.begin(),v.end(),isEven);
    cout<<*it<<endl;
    */
    /*
    // find_end
    vector<int> haystack = {1,2,3,4,5,1,2,3,4,5};
    vector<int> needle1 = {1,2,3};
    auto it = find_end (haystack.begin(), haystack.end(), needle1.begin(), needle1.end());
    if (it!=haystack.end())
      cout << "needle1 last found at position " << (it-haystack.begin()) << '\n'; // prints distance since begin
    vector<int> needle2 = {4,5,1};
    it = find_end (haystack.begin(), haystack.end(), needle2.begin(), needle2.end(), myfunction);
    if (it!=haystack.end())
      cout << "needle2 last found at position " << (it-haystack.begin()) << '\n';
    */
    /*
    // find_first_of
    vector<int> haystack = {1,2,3,4,5,1,2,3,4,5};
    vector<int> needle1 = {1,2,3};
    auto it = find_first_of (haystack.begin(), haystack.end(), needle1.begin(), needle1.end());
    if (it!=haystack.end())
      cout << "needle1 first found at position " << (it-haystack.begin()) << '\n'; // prints distance since begin
    vector<int> needle2 = {4,5,1};
    it = find_end (haystack.begin(), haystack.end(), needle2.begin(), needle2.end(), myfunction);
    if (it!=haystack.end())
      cout << "needle2 first found at position " << (it-haystack.begin()) << '\n';
    // vector<int> needle3 = {6,5,1};
    // it = find_end (haystack.begin(), haystack.end(), needle3.begin(), needle3.end(), myfunction);
    // if (it!=haystack.end())
    //   cout << "needle3 first found at position " << (it-haystack.begin()) << '\n';
    // else{
    //     cout << "needle3 not found" << endl;
    // }
    */
    /*
    // adjacent_find
    vector<int> v = {1,2,3,4,4,6};
    // vector<int> v = {1,2,3,4,5,6}; // returns v.end()
    cout<<*(adjacent_find(v.begin(),v.end()))<<endl;
    // cout<<*(v.end())<<endl;
    */
    /*
    // count/count_if
    vector<int> v = {1,2,2,3,3,3,4,4,4,4};
    cout<<"Number of fours in vector : "<<count(v.begin(),v.end(),4)<<endl;
    cout<<"Number of even in vector : "<<count_if(v.begin(),v.end(),isEven)<<endl;
    cout<<"Number of numbers > 2 in vector : "<<count_if(v.begin(),v.end(),[](int i){ return i>2;})<<endl;
    */
    /*
    //  mismatch
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2 = {1,2,3,5,6,7};
    auto ptrs = mismatch(v.begin(),v.end(),v2.begin());
    cout<<"ptr1 : "<<*(ptrs.first)<<" ptr2 : "<<*(ptrs.second)<<endl;
    */
    /*
    // equal
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2 = {1,2,3,4,5,6};
    // vector<int> v2 = {1,2,3,5,6,7};
    cout<<"v == v2 : "<<equal(v.begin(),v.end(),v2.begin())<<endl;
    */
    /*
    // is_permutation
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2 = {3,4,5,6,1,2};
    // vector<int> v2 = {3,4,5,6,2,1};
    // vector<int> v2 = {3,4,5,6,1,3};
    cout<<"v2 permutation of v ? : "<<is_permutation(v.begin(),v.end(),v2.begin())<<endl;
    */
    /*
    // search/search_n
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2 = {3,4};
    // vector<int> v2 = {2,4}; // points at end
    auto it = search(v.begin(),v.end(),v2.begin(),v2.end());
    cout<<"Position of sub-sequence : "<<int(it - v.begin())<<endl;
    it = search_n(v.begin(),v.end(),1,5);
    cout<<"Position of sub-sequence : "<<int(it - v.begin())<<endl;
    */
    /*
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2(6);
    
    // copy
    copy(v.begin(),v.end(),v2.begin());
    cout<<"v : ";showVec(v);
    cout<<"v2 : ";showVec(v2);
    
    // copy_n
    copy_n(v.begin()+2,4,v2.begin());
    cout<<"v : ";showVec(v);
    cout<<"v2 : ";showVec(v2);
    
    // copy_if
    vector<int> v3(3);
    copy_if(v.begin(),v.end(),v3.begin(),isEven);
    cout<<"v : ";showVec(v);
    cout<<"v3 : ";showVec(v3);
    
    // copy_backward
    vector<int> v4(6);
    copy_backward(v.begin(),v.end(),v4.end());
    cout<<"v : ";showVec(v);
    cout<<"v4 : ";showVec(v4);
    */
    /*
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2(6);
    
    // move
    move(v.begin(),v.end(),v2.begin());
    cout<<"v : ";showVec(v); // each in an unspecified but valid state
    cout<<"v2 : ";showVec(v2);
    
    // move
    vector<int> v3(6);
    v3 = move(v);
    cout<<"v : ";showVec(v); // v is in an unspecified but valid state
    cout<<"v3 : ";showVec(v3);

    // move_backward
    vector<int> v4(6);
    move_backward(v3.begin(),v3.end(),v4.end());
    cout<<"v3 : ";showVec(v3);
    cout<<"v4 : ";showVec(v4);
    */
    /*
    // swap
    int a = 5;
    int b = 6;
    swap(a,b);
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2 = {6,7,8,9};
    swap(v,v2);
    cout<<"v : ";showVec(v);
    cout<<"v2 : ";showVec(v2);

    // swap ranges
    swap_ranges(v2.begin(),v2.end(),v.begin());
    cout<<"v : ";showVec(v);
    cout<<"v2 : ";showVec(v2); // since size not changed hence garbage value at end

    // iter_swap
    iter_swap(v.begin(),v2.begin());
    cout<<"v : ";showVec(v);
    cout<<"v2 : ";showVec(v2); 
    */
    /*
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v2(6);
    
    // transform
    transform(v.begin(),v.end(),v2.begin(),[](int i){ return ++i;});
    cout<<"v : ";showVec(v);
    cout<<"v2 : ";showVec(v2);

    vector<int> v3(6);
    transform(v.begin(),v.end(),v2.begin(),v3.begin(),[](int i, int j){ return i+j;});
    cout<<"v3 : ";showVec(v3);
    */
    /*
    vector<int> v = {1,2,3,8,5,6,7};
    // replace
    replace(v.begin(),v.end(),8,4);
    cout<<"v : ";showVec(v);

    // replace_if
    replace_if(v.begin(),v.end(),[](int i){return (i%2)==0;},0);
    cout<<"v : ";showVec(v);

    vector<int> v2(7);
    // replace_copy
    replace_copy(v.begin(),v.end(),v2.begin(),0,2);
    cout<<"v2 : ";showVec(v2);

    // replace_copy_if
    replace_copy_if(v2.begin(),v2.end(),v2.begin(),[](int i){return (i%2)==1;},1);
    cout<<"v2 : ";showVec(v2);
    */
   // not all covered
    return 0;
}