//6. Write a Java program to swap two variables
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value of x: ");
        int x = s.nextInt();
        System.out.print("Enter the value of y: ");
        int y = s.nextInt();
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
        System.out.println("After Swapping");
        System.out.println("Value of x: "+x);
        System.out.println("Value of y: "+y);
    }
}