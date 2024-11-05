// FIND THE LARGEST ELEMENT IN THE INTEGER ARRAY USING RECURSION.

#include <stdio.h>

int findLargest(int arr[], int n) {
    if (n == 1)
        return arr[0];

    int maxOfRest = findLargest(arr + 1, n - 1);

    if (arr[0] > maxOfRest)
        return arr[0];
    else
        return maxOfRest;
}

int main() {
    int arr[] = {12, 34, 54, 2, 99, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = findLargest(arr, n);
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}
