#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &vect,int target){
    int high = vect.size() - 1;
    int low = 0;
    int mid;
    while (low <= high)
    {
        // mid = (high+low)/2;
        /*
            for very large array of size with high -> 2^31 and low -> 2^31
            low + high -> would not be possible as it couldn't be stored
            to avoid this failure we can do high + (high-low)/2
            since high-low < high hence this mid process failure would be avoided
        */
        mid = low+(high-low)/2
        int term = vect[mid];
        if (term == target){
            return mid;
        }
        else if( term < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
    
}
int main() {
    vector<int> vect = {1,2,4,5};
    // int num;
    // cout<<"Enter target : ";
    // cin>>num;
    cout<<binarySearch(vect,3)<<endl;
    return 0;
}
/*
    target - 4

    1 2 3 4 5 6 7
    L   M       H
        L   M   H
        L M H
*/