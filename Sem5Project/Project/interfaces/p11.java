// 11. Write a Java program to create an interface Sortable with a method sort (int[] array) that sorts an array of integers in descending order. Create two classes QuickSort and MergeSort that implement the Sortable interface and provide their own implementations of the sort() method.

interface Sortable {
    void sort(int[] array);
}

class QuickSort implements Sortable {
    public void sort(int[] array) {
        quickSort(array, 0, array.length - 1);
    }

    void quickSort(int[] arr, int low, int high) {
        if(low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(arr[j] > pivot) { // descending
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        return i+1;
    }
}

class MergeSort implements Sortable {
    public void sort(int[] array) {
        mergeSort(array, 0, array.length - 1);
    }

    void mergeSort(int[] arr, int l, int r) {
        if(l < r) {
            int m = (l + r) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }

    void merge(int[] arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for(int i = 0; i < n1; i++) L[i] = arr[l+i];
        for(int j = 0; j < n2; j++) R[j] = arr[m+1+j];

        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(L[i] >= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while(i < n1) arr[k++] = L[i++];
        while(j < n2) arr[k++] = R[j++];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] arr1 = {5, 2, 9, 1, 5};
        int[] arr2 = {7, 3, 8, 4, 2};

        Sortable qSort = new QuickSort();
        qSort.sort(arr1);
        System.out.print("QuickSort Descending: ");
        for(int num : arr1) System.out.print(num + " ");
        System.out.println();

        Sortable mSort = new MergeSort();
        mSort.sort(arr2);
        System.out.print("MergeSort Descending: ");
        for(int num : arr2) System.out.print(num + " ");
        System.out.println();
    }
}

/*
Output:
QuickSort Descending: 9 5 5 2 1 
MergeSort Descending: 8 7 4 3 2 
*/
