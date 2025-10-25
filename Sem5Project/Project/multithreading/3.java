// 3. Write a Java program that sorts an array of integers using multiple threads.

import java.util.Arrays;

class SortThread extends Thread {
    private int[] arr;

    SortThread(int[] arr) {
        this.arr = arr;
    }

    public void run() {
        Arrays.sort(arr);
    }

    public int[] getSortedArray() {
        return arr;
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int[] arr = {9, 4, 7, 1, 3, 6, 8, 2, 5, 0};

        
        int mid = arr.length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);

       
        SortThread t1 = new SortThread(left);
        SortThread t2 = new SortThread(right);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

       
        int[] sorted = merge(t1.getSortedArray(), t2.getSortedArray());

        System.out.println("Sorted array: " + Arrays.toString(sorted));
    }

    static int[] merge(int[] a, int[] b) {
        int[] merged = new int[a.length + b.length];
        int i = 0, j = 0, k = 0;

        while (i < a.length && j < b.length) {
            if (a[i] <= b[j]) merged[k++] = a[i++];
            else merged[k++] = b[j++];
        }
        while (i < a.length) merged[k++] = a[i++];
        while (j < b.length) merged[k++] = b[j++];

        return merged;
    }
}

/*
Output:
Sorted array: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/
