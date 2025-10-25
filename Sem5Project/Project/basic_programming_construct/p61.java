//61. Write a Java program to display the n terms of odd natural number and their sum    
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value: ");
        int sum = 0, n = s.nextInt();
        System.out.print("First "+ n +" odd natural numbers: ");
        for(int i=1;n>0;i+=2,n--)
        {
            System.out.print(i + " ");
            sum += i;
        }
        System.out.println("\nSum is "+ sum);
    }
}

