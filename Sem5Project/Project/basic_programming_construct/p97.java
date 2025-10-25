import java.util.Scanner;

public class SegregateZeroOne {
    static void segregate(int[] arr) {
        int countZero = 0;
        for(int num : arr) {
            if(num == 0)
                countZero++;
        }
        for(int i=0; i<arr.length; i++) {
            if(i < countZero)
                arr[i] = 0;
            else
                arr[i] = 1;
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
        System.out.println("Enter elements (0 or 1 only):");
        for(int i=0; i<n; i++) 
            arr[i] = sc.nextInt();

        segregate(arr);
        System.out.print("After segregation: ");
        printArray(arr);
        sc.close();
    }
}
output:-
        Enter array size: 8
        Enter elements (0 or 1 only):
        0 1 0 1 1 0 0 1
        After segregation: 0 0 0 0 1 1 1 1 
        