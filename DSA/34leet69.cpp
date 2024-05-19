#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        long long int mid = 0;
        int high = x;
        while (low<=high){
            mid = low + (high-low)/2;
            if ((mid*mid) == x){
                return mid;
            }
            else if ((mid*mid) > x){
                mid--;
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return mid;
    }
};
int main(){
    Solution temp;
    cout<<temp.mySqrt(1);
}