// 7. Write a Java program to create an interface Sortable with a method sort() that sorts an array of integers in ascending order. Create two classes BubbleSort and SelectionSort that implement the Sortable interface and provide their own implementations of the sort() method.

interface Sortable {
    void sort(int[] arr);
}

class BubbleSort implements Sortable {
    public void sort(int[] arr) {
        int n = arr.length;
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}

class SelectionSort implements Sortable {
    public void sort(int[] arr) {
        int n = arr.length;
        for(int i = 0; i < n-1; i++) {
            int minIdx = i;
            for(int j = i+1; j < n; j++) {
                if(arr[j] < arr[minIdx]) minIdx = j;
            }
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int[] arr1 = {5, 2, 9, 1, 5};
        int[] arr2 = {7, 3, 8, 4, 2};

        Sortable bSort = new BubbleSort();
        bSort.sort(arr1);
        System.out.print("BubbleSort: ");
        for(int num : arr1) System.out.print(num + " ");
        System.out.println();

        Sortable sSort = new SelectionSort();
        sSort.sort(arr2);
        System.out.print("SelectionSort: ");
        for(int num : arr2) System.out.print(num + " ");
        System.out.println();
    }
}

/*
Output:
BubbleSort: 1 2 5 5 9 
SelectionSort: 2 3 4 7 8 
*/
