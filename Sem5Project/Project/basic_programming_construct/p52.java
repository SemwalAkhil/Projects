//52. Write a Java program to take three numbers from the user and print the greatest number
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the 1st number: ");
        int a = sc.nextInt();
        System.out.print("Enter the 2nd number: ");
        int b = sc.nextInt();
        a = (a>b)?a:b;
        System.out.print("Enter the 3rd number: ");
        b = sc.nextInt();
        a = (a>b)?a:b;
        System.out.println(a + " is greatest number!");
    }
}