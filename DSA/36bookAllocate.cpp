#include <iostream>
#include <vector>
using namespace std;
//  Allocate Books

// Problem statement
// Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

// There are ‘m’ number of students, and the task is to allocate all the books to the students.

// Allocate books in such a way that:

// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.

// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

// If the allocation of books is not possible, return -1.

// Example:
// Input: ‘n’ = 4 ‘m’ = 2 
// ‘arr’ = [12, 34, 67, 90]

// Output: 113

// Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

// 12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

// 12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

// 12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

// We are getting the minimum in the last case.

// Hence answer is ‘113’.
int isPossible(vector<int> &arr, int n, int m,int mid) {
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i<n ; i++){
        if (pageSum + arr[i] <= mid){ 
            pageSum += arr[i]; // while sum <= mid add element to sum
        }
        else{
            studentCount++; // if sum > mid add a new student
            if ((studentCount > m) || (arr[i] > mid)){
                return false; // if studentCount > m or pages > mid return false
                                    //                                    |-> because if pages > mid , sum cannot be less than mid
            }
            pageSum = arr[i]; // in case possible the sum = next arr element
        }
    }
    return true; // in case entire loop runs then possible solution
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (n >= m){ // number of books > number of student
        int s = 0; // start 
        int sum = 0;
        for (int i = 0 ; i <n ; i++){
            sum+= arr[i];
        }
        int e = sum; // end
        int ans = -1; // setting ans -1 for case where no possible solution
        int mid = s + (e-s)/2; // mid
        while (s<=e){ // start <=  end
            if (isPossible(arr,n,m,mid)){
                ans = mid; // if possible solution then set to answer
                e = mid-1; // look for smaller solution
            }
            else{
                s=mid+1; // if not possible solution look for a larger solution
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    return -1;
}
int main() {
    vector<int> arr = {1, 17, 14, 9, 15, 9, 14};
    cout<<findPages(arr,7,7)<<endl;
    // vector<int> arr = {12, 34, 67, 90};
    // cout<<findPages(arr,4,2)<<endl;
    return 0;
}