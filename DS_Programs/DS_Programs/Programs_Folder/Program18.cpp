// ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION

#include <stdio.h>

int linearSearch(int arr[], int n, int target, int index) {
    if (index == n)
        return -1;

    if (arr[index] == target)
        return index;

    return linearSearch(arr, n, target, index + 1);
}

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the integer value to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target, 0);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
