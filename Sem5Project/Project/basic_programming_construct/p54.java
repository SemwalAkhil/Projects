//54. Write a Java program to test a number is positive or negative
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n = sc.nextInt();
        if(n>0)
            System.out.println("Number is Positive!");
        else if (n == 0)
            System.out.println("Number is Zero!");
        else
            System.out.println("Number is Negative!");
    }
}