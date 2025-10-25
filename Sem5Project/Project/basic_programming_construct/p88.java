//88. Write a Java program to reverse an array of integer values
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int i = 0, n = s.nextInt();
        int arr[]= new int[n];
        System.out.print("Enter the values: ");
        for(i = 0; i < n; i++)
            arr[i] = s.nextInt();
        for(i = 0; i < n/2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
        System.out.print("Reversed Array: ");
        for(i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }
}