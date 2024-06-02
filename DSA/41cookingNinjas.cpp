#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &rank, int m, int mid){
    int time = 0;
    int dishCount = 0;
    int count = 1;
    for(int i = 0; i < rank.size(); i++){
        time += rank[i] * count;
        while ( time <= mid){
            count += 1;
            dishCount += 1;
            time += rank[i] * count;
        }
        count = 1;
        time = 0;
    }
    if (dishCount < m){
        return false;
    }
    else{
        return true;
    }
} 
int minCookTime(vector<int> &rank, int m)
{
    sort(rank.begin(),rank.end());
    // Write your code here
    int low = 0;
    int high = (rank[rank.size() - 1])*m*m;
    int mid = 0;
    int ans = 0;
    while (low <=  high){
        mid = low + (high-low)/2 ;
        if (isPossible(rank, m, mid)){
            high = mid - 1;
            ans = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> ranks = {1,2,3,4};
    cout<<minCookTime(ranks,11)<<endl;
    return 0;
}