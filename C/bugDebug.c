/*
    1. selection sort   -> compares minimum with all element one by one starting from first unsorted element
    2. bubble sort      -> compares adjacent element
*/
#include <stdio.h>
void display(int arr[], int len)                //  O(n)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[], int len)         //   O(n²)
{
    int min;
    for (int i = 0; i < len; i++)       // iterates until first unsorted element
    {
        min = arr[i];                   // set first unsorted element minimum { 1 , 4 , 3 , 2 , 5 }
                                                                          //min-^
        for (int j = i; j < len; j++)   // iterates through unsorted array 
        {
            if (arr[j] < min)           // compares the elements from unsorted array elements with minimum
            {
                arr[i] = arr[j];        // swaps the elements
                arr[j] = min;          
                min = arr[i];           // new minimum assigned
            }
        }
    }
}
void bubbleSort(int arr[], int len){            // O(n²)
    int temp;
    for (int i = 0; i < len; i++)               // iteration 1
    {
        for (int j = 0; j+1 < len; j++)         // iteration 2
        {
            if (arr[j] > arr[j+1]){             // if element is greater than next element then they are swapped
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            display(arr, len);
        }
    }   
}
void pyramid(int row){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= (row - i); j++)    // leaves spaces before drawing star spaces decrease as star increase 
        {
            printf(" ");
        }
        for (int j = 0; j <= 2*i; j++)          // draws (twice + 1) the number of stars as spaces left giving pyramid shape
        {
            printf("*");
        }
        printf("\n");                           // inserts new line after each line of stars   
    }
}
void linearSearch(int arr[], int len, int ele){         // O(n)
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == ele)
        {
            printf("%d at index %d\n",ele,i);
            return ;
        }
    }
    printf("Element not found\n"); 
}
void binarySearch(int arr[], int len, int ele){     // !!! works only on sorted array !!!       // O(log2)
    int upper,lower,mid;
    upper = len-1;                                  // last element upper limit
    lower = 0;                                      // first element lower limit
    mid = (len/2);                                  // middle element
    while (lower < upper)
    {
        if (arr[mid] < ele)                         // if element is greater than mid element lower half is ignored
        {
            lower = mid + 1;                        // mid + 1 because arr[mid] != ele but less
        }
        else if (arr[mid] > ele)                    // if element is greater than mid element upper half is ignored
        {
            upper = mid - 1;                        // mid - 1 because arr[mid] != ele but greater
        }
        else
        {
            break;                                  // mid == element then break
        }
        mid = (lower + upper)/2 ;                   // set new mid for new lower and upper
    }
    if (arr[mid] == ele)
    {
        printf("%d at index %d\n",ele,mid);
    }
    else
    {
        printf("Element not found\n");
    }
}

int main()
{
    int arr[] = {1,4,3,5,2};
    // selectionSort(arr, 5);
    // display(arr, 5);
    // bubbleSort(arr, 5);
    // display(arr, 5);
    // pyramid(5);
    // linearSearch(arr,5,4);
    int arr2[] = {1,2,4,5,6};
    linearSearch(arr2,5);
    
    return 0;
}
