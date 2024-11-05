/*
 Find Next Smaller Element

Explanation -

Given an array, print the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element on the right side of x in the array. Elements for which no smaller element exist (on the right side), consider NSE as -1. Examples: Input: [4, 8, 5, 2, 25] Output: [2, 5, 2, -1, -1] Explanation: The first element smaller than 4 having index > 0 is 2. The first element smaller than 8 having index > 1 is 5. The first element smaller than 5 having index > 2 is 2. There are no elements smaller than 4 having index > 3. There are no elements smaller than 4 having index > 4. Input: [13, 7, 6, 12] Output: [7, 6, -1, -1] Explanation: The first element smaller than 13 having index > 0 is 7. The first element smaller than 7 having index > 1 is 6. There are no elements smaller than 6 having index > 2. There are no elements smaller than 12 having index > 3.
*/

#include <iostream>

int* nextSmallerElement(int arr[], int n) {
    int* result = new int[n];  // Dynamic array to store the results
    int stack[n];              // Stack to store indices
    int top = -1;              // Initialize the stack pointer

    // Initialize the result array with -1 (default value if no smaller element exists)
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack while the stack is not empty and the top element of stack is greater than or equal to arr[i]
        while (top != -1 && arr[stack[top]] >= arr[i]) {
            top--;
        }

        // If the stack is not empty, then the top element of the stack is the next smaller element
        if (top != -1) {
            result[i] = arr[stack[top]];
        }

        // Push the current element index onto the stack
        stack[++top] = i;
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int* result = nextSmallerElement(arr, n);

    std::cout << "Next Smaller Element for each element is: ";
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    delete[] result; // Free the dynamically allocated memory

    return 0;
}

