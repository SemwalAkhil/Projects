/* Trapping Rain Water Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Explanation -

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1] Output: 6 Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.*/

#include <iostream>
using namespace std;

int trapRainWater(int height[], int n) {
    if (n <= 2) return 0; 

    int left = 0, right = n - 1;      
    int leftMax = 0, rightMax = 0;   
    int waterTrapped = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            ++left;
        } else {
            
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            --right;
        }
    }

    return waterTrapped;
}

int main() {
    int n;
    cout << "Enter the number of elements in the height array: ";
    cin >> n;

    int height[n];
    cout << "Enter the elements of the height array: ";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int result = trapRainWater(height, n);
    cout << "Total water trapped: " << result << endl;

    return 0;
}
