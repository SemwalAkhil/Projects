//87. Write a Java program to insert an element (specific position) into an array
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int i = 0, n = s.nextInt();
        int arr[]= new int[n+1];
        System.out.print("Enter the values: ");
        for(i = 0; i < n; i++)
            arr[i] = s.nextInt();
        System.out.print("Enter the value you want to insert: ");
        int x = s.nextInt();
        System.out.print("Enter the position: ");
        int pos = s.nextInt();
        for(i = n++; i >= pos; i--)
            arr[i] = arr[i - 1];
        arr[pos - 1] = x;
        System.out.print("Final Array: ");
        for(i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }
}