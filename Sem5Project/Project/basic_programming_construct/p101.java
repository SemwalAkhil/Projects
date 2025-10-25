import java.util.Scanner;

public class DescendingSort {
    static void sortDescending(int[] arr) {
        int temp;
        for(int i=0; i<arr.length-1; i++) {
            for(int j=i+1; j<arr.length; j++) {
                if(arr[i] < arr[j]) {  // Change comparator for descending
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    static void printArray(int[] arr) {
        for(int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements:");
        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

        sortDescending(arr);
        System.out.print("Sorted array in descending order: ");
        printArray(arr);
        sc.close();
    }
}
output:-
        Enter the size of array: 6
        Enter the elements:
        30 10 50 20 40 60
        Sorted array in descending order: 60 50 40 30 20 10 
        