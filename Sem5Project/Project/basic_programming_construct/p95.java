import java.util.Scanner;

public class EvenOddCount {
    static void countEvenOdd(int[] arr) {
        int evenCount = 0, oddCount = 0;
        for(int num : arr) {
            if(num % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
        System.out.println("Even numbers: " + evenCount);
        System.out.println("Odd numbers: " + oddCount);
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Enter array elements:");
        for(int i=0; i<n; i++)
            array[i] = sc.nextInt();

        countEvenOdd(array);
        sc.close();
    }
}
output:-
        Enter array size: 6
        Enter array elements:
        10 7 4 9 12 3
        Even numbers: 3
        Odd numbers: 3
        