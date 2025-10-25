import java.util.Scanner;

public class SumEvenOdd {
    static int[] sumEvenOdd(int[] arr) {
        int evenSum = 0, oddSum = 0;
        for(int num : arr) {
            if(num % 2 == 0)
                evenSum += num;
            else
                oddSum += num;
        }
        return new int[]{evenSum, oddSum};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements:");
        for(int i=0;i<n;i++) arr[i] = sc.nextInt();

        int[] sums = sumEvenOdd(arr);
        System.out.println("Sum of even numbers: " + sums[0]);
        System.out.println("Sum of odd numbers: " + sums[1]);
        sc.close();
    }
}
output:-
        Enter array size: 6
        Enter elements:
        1
        2
        3
        4
        5
        6
        Sum of even numbers: 12
        Sum of odd numbers: 9
        