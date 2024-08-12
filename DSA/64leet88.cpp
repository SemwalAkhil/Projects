#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        for (int i = 0; i < n; i++)
        {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n- 1;
        while (j >= 0){
            if (i >= 0 && nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
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
};
int main() {
    Solution a;
    // vector<int> v = {1,2,3,0,0,0};
    // vector<int> v2 = {2,5,6};
    // a.merge2(v,3,v2,3);

    // vector<int> v = {1};
    // vector<int> v2 = {};
    // a.merge2(v,1,v2,0);

    // vector<int> v = {0};
    // vector<int> v2 = {1};
    // a.merge2(v,0,v2,1);

    vector<int> v = {2,0};
    vector<int> v2 = {1};
    a.merge2(v,1,v2,1);
    cout<<"vec: ";a.showVec(v);
    return 0;
}