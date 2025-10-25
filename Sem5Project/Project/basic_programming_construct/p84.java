//84. Write a Java program to calculate the average value of array elements
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = s.nextInt(),sum = 0;
        int arr[]= new int[n];
        System.out.print("Enter the values: ");
        for(int i = 0; i < n; i++){
            arr[i] = s.nextInt();
            sum += arr[i];
        }
        System.out.println("Average of all values: " +((float)sum/n));
    }
}