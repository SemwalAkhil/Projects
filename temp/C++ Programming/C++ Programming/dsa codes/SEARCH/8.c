#include <stdio.h>
#define maxSize 100

int binarySearch(char arr[], int size, char ele) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == ele) {
            return mid;
        } else if (arr[mid] > ele) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    char arr[maxSize];
    int size;
    char search;
    int result;

    printf("ENTER SIZE OF ARRAY: ");
    scanf("%d", &size);
    getchar(); // To consume newline character

    for (int i = 0; i < size; i++) {
        printf("ENTER ELEMENT %d: ", i);
        scanf("%c", &arr[i]);
        getchar(); // To consume newline character
    }

    printf("ENTER ELEMENT TO BE SEARCHED: ");
    scanf("%c", &search);
    
    result = binarySearch(arr, size, search);
    
    if (result >= 0) {
        printf("ELEMENT FOUND AT INDEX %d\n", result);
    } else {
        printf("ELEMENT NOT FOUND\n");
    }
    
    return 0;
}
