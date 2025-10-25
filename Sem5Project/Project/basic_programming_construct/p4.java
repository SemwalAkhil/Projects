//4. Write a Java program to print the sum, multiply, subtract, divide and remainder of two numbers
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value of x: ");
        int x = s.nextInt();
        System.out.print("Enter the value of y: ");
        int y = s.nextInt();
        System.out.println("Sum of "+x+" and "+y+" is "+(x+y));
        System.out.println("Difference of "+x+" and "+y+" is "+(x-y));
        System.out.println("Product of "+x+" and "+y+" is "+(x*y));
        System.out.println("Division of "+x+" by "+y+" is "+(x/y));
        System.out.println("Remainder of "+x+" by "+y+" is "+(x%y));
    }
}