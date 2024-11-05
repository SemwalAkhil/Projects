/* Find the Next Greater Element

Explanation -

Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1. Example 1: Input: N = 4, arr[] = [1 3 2 4] Output: 3 4 4 -1 Explanation: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist, it is -1. Example 2: Input: N = 5, arr[] [6 8 0 1 3] Output: 8 -1 1 3 -1 Explanation: In the array, the next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.*/
#include <iostream>

int* nextGreaterElement(int arr[], int n) {
    int* result = new int[n];  // Dynamic array to store the results
    int stack[n];              // Stack to store indices
    int top = -1;              // Initialize the stack pointer

    // Initialize the result array with -1
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        // While the stack is not empty and the current element is greater
        // than the element corresponding to the index on top of the stack
        while (top != -1 && arr[i] > arr[stack[top]]) {
            result[stack[top]] = arr[i];  // Set NGE for the element at stack's top index
            top--;                         // Pop the index from the stack
        }
        stack[++top] = i; // Push the current index onto the stack
    }

    // Any indices left in the stack will have -1 as their NGE, so they remain unchanged

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

    int* result = nextGreaterElement(arr, n);

    std::cout << "Next Greater Element for each element is: ";
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    delete[] result; // Free the dynamically allocated memory

    return 0;
}
