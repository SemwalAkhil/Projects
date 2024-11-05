// FIND THE ARITHMETIC MEAN OF AN INTEGER ARRAY USING RECURSION

#include <stdio.h>

int sumArray(int arr[], int n) {
    if (n == 0)
        return 0;
    
    return arr[n - 1] + sumArray(arr, n - 1);
}

double findMean(int arr[], int n) {
    int sum = sumArray(arr, n);
    return (double)sum / n;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    double mean = findMean(arr, n);
    printf("The arithmetic mean of the array is: %.2f\n", mean);

    return 0;
}
