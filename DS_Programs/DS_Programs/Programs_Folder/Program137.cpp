/* Find the first circular tour that visits all petrol pumps

Explanation -

Given information about N petrol pumps (say arr[]) that are present in a circular path. The information consists of the distance of the next petrol pump from the current one (in arr[i][1]) and the amount of petrol stored in that petrol pump (in arr[i][0]). Consider a truck with infinite capacity that consumes 1 unit of petrol to travel 1 unit distance. The task is to find the index of the first starting point such that the truck can visit all the petrol pumps and come back to that starting point. Note: Return -1 if no such tour exists. Examples: Input: arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}}. Output: 1 Explanation: If started from 1st index then a circular tour can be covered. Input: arr[] {{6, 4}, {3, 6}, {7, 3}} Output: 2*/

#include <iostream>
#include <vector>

int findStartingPoint(const std::vector<std::vector<int>>& arr) {
    int n = arr.size();
    int start = 0;            // Starting index of the petrol pump
    int totalPetrol = 0;       // Total petrol balance (net petrol after covering all distances)
    int currentPetrol = 0;     // Petrol balance for the current tour segment

    for (int i = 0; i < n; i++) {
        totalPetrol += arr[i][0] - arr[i][1];  // Net petrol gain/loss for each pump
        currentPetrol += arr[i][0] - arr[i][1];

        // If current petrol balance is negative, reset starting point
        if (currentPetrol < 0) {
            start = i + 1;        // Move start to the next pump
            currentPetrol = 0;    // Reset current petrol balance
        }
    }

    // If total petrol is negative, it's impossible to complete the tour
    return (totalPetrol >= 0) ? start : -1;
}

int main() {
    int n;
    std::cout << "Enter the number of petrol pumps: ";
    std::cin >> n;

    std::vector<std::vector<int>> arr(n, std::vector<int>(2));

    // Taking input from the user
    for (int i = 0; i < n; i++) {
        std::cout << "Enter petrol and distance for pump " << i << ": ";
        std::cin >> arr[i][0] >> arr[i][1];
    }

    int start = findStartingPoint(arr);
    
    if (start != -1) {
        std::cout << "Starting point for circular tour: " << start << "\n";
    } else {
        std::cout << "No circular tour possible.\n";
    }

    return 0;
}


