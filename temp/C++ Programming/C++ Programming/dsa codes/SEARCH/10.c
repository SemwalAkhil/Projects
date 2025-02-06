#include <stdio.h>
#include <time.h>
#define maxSize 100

int binarySearch(int arr[], int low, int high, int ele) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == ele) {
        return mid;
    } else if (arr[mid] > ele) {
        return binarySearch(arr, low, mid - 1, ele);
    } else {
        return binarySearch(arr, mid + 1, high, ele);
    }
}

int main() {
    int arr[maxSize], size, search, result;
    clock_t start, end;

    printf("ENTER SIZE OF ARRAY: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("ENTER ELEMENT %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("ENTER ELEMENT TO BE SEARCHED: ");
    scanf("%d", &search);
    
    start = clock();
    result = binarySearch(arr, 0, size - 1, search);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result >= 0) {
        printf("ELEMENT FOUND AT INDEX %d\n", result);
    } else {
        printf("ELEMENT NOT FOUND\n");
    }
    printf("TIME TAKEN: %f seconds\n", time_taken);
    
    return 0;
}
