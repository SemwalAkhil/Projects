import java.util.Scanner;

public class AscendingSort {
    static void sortAscending(int[] arr) {
        int temp;
        for(int i=0; i<arr.length-1; i++) {
            for(int j=i+1; j<arr.length; j++) {
                if(arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    static void printArray(int[] arr) {
        for(int num : arr)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for(int i=0; i<n; i++) 
            arr[i] = sc.nextInt();

        sortAscending(arr);

        System.out.print("Sorted array: ");
        printArray(arr);
        sc.close();
    }
}
output:-
        Enter array size: 6
        Enter array elements:
        30 10 50 20 40 60
        Sorted array: 10 20 30 40 50 60 
        