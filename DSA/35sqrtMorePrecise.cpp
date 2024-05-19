#include<iostream>
using namespace std;
class Solution {
public:
    double mySqrt(int x){
        double base = double(baseRoot(x));
        double precision = 0.1;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                base += precision;
                if ((base*base) > x){
                    base -= precision;
                    break;
                }
                else if((base*base) == x){
                    break;
                }
            }
            precision /= 10;
        }
        return base;
    }
    int baseRoot(int x) {
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
    cout<<temp.mySqrt(8);
}