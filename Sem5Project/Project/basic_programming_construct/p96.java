import java.util.Scanner;

public class MaxMinDifference {
    static int findDifference(int[] arr) {
        int max = arr[0];
        int min = arr[0];
        for(int num : arr) {
            if(num > max)
                max = num;
            if(num < min)
                min = num;
        }
        return max - min;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Enter elements:");
        for(int i=0; i<n; i++) 
            array[i] = sc.nextInt();

        System.out.println("Difference (max-min): " + findDifference(array));
        sc.close();
    }
}
output:-
         Enter array size: 5
         Enter elements:
         10 5 20 8 15
         Difference (max-min): 15
         