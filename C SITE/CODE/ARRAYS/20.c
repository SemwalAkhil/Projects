// 20. Trapping Rain Water Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
/*
Explanation -

    Input : height = [ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 ]
    Output : 6
    Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.
                     _
             _      | |_   _      3
         _  | |_   _|   |_| |_    2
        |_|_|_ _|_|_ _ _ _ _ _|   1
*/
#include <stdio.h>
/*
The solution involves finding the water trapped above each bar by identifying the amount of water it can hold based on the height of its neighboring bars. Here's how to approach it:
    Identify the maximum heights to the left and right of each bar:
        For each bar, we need to know the maximum height to its left and the maximum height to its right.
    Calculate water trapped above each bar:
        For each bar at index 𝑖, the water it can trap depends on the minimum of the maximum heights to its left and right, minus the height of the bar itself.
    Sum up the trapped water above each bar.
*/
#include <stdio.h>

int trapRainWater(int *height, int n)
{
    if (n <= 2)
        return 0; // Not enough bars to trap any water

    int leftMax[n], rightMax[n];
    int waterTrapped = 0;

    // Fill leftMax array
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = (height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1];
    }

    // Fill rightMax array
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = (height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1];
    }

    // Calculate total water trapped
    for (int i = 0; i < n; i++)
    {
        int minHeight = (leftMax[i] < rightMax[i]) ? leftMax[i] : rightMax[i];
        if (minHeight > height[i])
        {
            waterTrapped += minHeight - height[i];
        }
    }

    return waterTrapped;
}

int main()
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);

    int result = trapRainWater(height, n);
    printf("Total water trapped: %d\n", result);

    return 0;
}
