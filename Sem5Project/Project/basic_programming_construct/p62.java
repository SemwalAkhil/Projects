//62. Write a Java program to display the multiplication table of a given integer
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value: ");
        int n = s.nextInt();
        System.out.println("Multiplication Table of "+ n +" :");
        for(int i=1;i<=10;i++)
        {
            System.out.println(n +" x "+ i +" = "+ (n*i));
        }
    }
}