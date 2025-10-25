//83. Write a Java program to find the index of an array element
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
        System.out.print("\nEnter the value you want to find: ");
        int f = s.nextInt();
        for(i = 0; i < n; i++){
            if(arr[i] == f)
                break;
        }
        if(i != n)
            System.out.println("Value " + f + " find at index: " + i);
        else
            System.out.println("Value " + f + " not found!");
    }
}