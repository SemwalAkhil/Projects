//65. Write a Java program that accepts three numbers and check All numbers are equal or not
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter 1st number: ");
        int n1 = s.nextInt();
        System.out.print("Enter 2nd number: ");
        int n2 = s.nextInt();
        System.out.print("Enter 3rd number: ");
        int n3 = s.nextInt();
        if(n1 == n2 && n2 == n3)
            System.out.println("All numbers are equal!");
        else
            System.out.println("All numbers are not equal!");
    }
}