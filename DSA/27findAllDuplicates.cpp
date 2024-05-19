/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // vector<int> findDuplicates(vector<int>& nums) {
    //     vector<int> count = {};
    //     vector<int> retList = {};
    //     for (int i = 0; i < nums.size(); i++){
    //         if (count.empty()) {
    //             count.push_back(nums.at(i));
    //         }
    //         else{
    //             auto it = find(count.begin(), count.end(), nums.at(i));
    //             if (it == count.end()){
    //                 count.push_back(nums.at(i));
    //             }
    //             else{
    //                 retList.push_back(nums.at(i));
    //             }
    //         }
    //     }
    //     return retList;
    // }
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> count(nums.size()+1,0);
        vector<int> retList = {};
        for (int i = 0; i < nums.size(); i++){
            count[nums[i]] += 1;
            // cout<<count[nums[i]]<<" "<<nums[i]<<endl;
            if (count[nums[i]] > 1){
                retList.push_back(nums[i]);
            }
        }
        return retList;
    }
};

int main() {
    Solution a;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> retList = a.findDuplicates(nums);
    for (int i = 0; i < retList.size(); i++)
    {
        cout<<retList.at(i)<<endl;
    }
    
    return 0;
}
