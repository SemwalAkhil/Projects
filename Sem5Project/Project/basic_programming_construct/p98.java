import java.util.Scanner;

public class RotateArray {
    static void rotateByOne(int[] arr) {
        int last = arr[arr.length-1];
        for(int i = arr.length-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }

    static void printArray(int[] arr) {
        for(int num : arr)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements:");
        for(int i=0; i<n; i++) 
            arr[i] = sc.nextInt();

        System.out.print("Before rotation: ");
        printArray(arr);

        rotateByOne(arr);

        System.out.print("After rotation: ");
        printArray(arr);
        sc.close();
    }
}
output:- 
        Enter array size: 5
        Enter elements:
        1 2 3 4 5
        Before rotation: 1 2 3 4 5 
        After rotation: 5 1 2 3 4 
        