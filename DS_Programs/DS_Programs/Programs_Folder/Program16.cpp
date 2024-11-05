// ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH ITERATION

#include <stdio.h>

void inputArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}
int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    
    inputArray(arr, n);


    printf("Enter the integer value to search for: ");
    scanf("%d", &target);


    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
