// FIND THE SMALLEST ELEMENT IN THE INTEGER ARRAY USING RECURSION.

#include <stdio.h>

int findSmallest(int arr[], int n) {
    if (n == 1)
        return arr[0];

    int minOfRest = findSmallest(arr + 1, n - 1);

    if (arr[0] < minOfRest)
        return arr[0];
    else
        return minOfRest;
}

int main() {
    int arr[] = {12, 34, 54, 2, 99, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallest = findSmallest(arr, n);
    printf("The smallest element in the array is: %d\n", smallest);

    return 0;
}
