// 13. Find the first circular tour that visits all petrol pumps
/*
Explanation -

        Given information about N petrol pumps(say arr[]) that are present in a circular path.The information consists of the distance of the next petrol pump from the current one(in arr[i][1]) and the amount of petrol stored in that petrol pump(in arr[i][0]).Consider a truck with infinite capacity that consumes 1 unit of petrol to travel 1 unit distance.The task is to find the index of the first starting point such that the truck can visit all the petrol pumps and come back to that starting point.Note : Return - 1 if no such tour exists.
        Examples :
        Input : arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}}.
        Output : 1
        Explanation : If started from 1st index then a circular tour can be covered.
        Input : arr[] {{6, 4}, {3, 6}, { 7, 3 }}
        Output : 2
*/
#include <stdio.h>

int circularTour(int arr[][2], int n)
{
    int total_petrol = 0, total_distance = 0;
    int current_petrol = 0, start_index = 0;

    for (int i = 0; i < n; i++)
    {
        total_petrol += arr[i][0];   // Total petrol available
        total_distance += arr[i][1]; // Total distance to travel

        current_petrol += arr[i][0] - arr[i][1]; // Current petrol after reaching the next pump

        // If current petrol drops below 0, reset the starting point
        if (current_petrol < 0)
        {
            start_index = i + 1; // Move the start index to the next pump
            current_petrol = 0;  // Reset current petrol
        }
    }

    // If total petrol is less than total distance, no solution exists
    if (total_petrol < total_distance)
    {
        return -1;
    }

    // Return the starting index
    return start_index;
}

int main()
{
    int arr1[][2] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = circularTour(arr1, n1);
    printf("Starting index for first tour in arr1: %d\n", result1); // Output: 1

    int arr2[][2] = {{6, 4}, {3, 6}, {7, 3}};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = circularTour(arr2, n2);
    printf("Starting index for first tour in arr2: %d\n", result2); // Output: 2

    return 0;
}
