//28. Java Program to find area of rectangle
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length: ");
        float l = sc.nextFloat();
        System.out.print("Enter the breadth: ");
        float b = sc.nextFloat();
        float area = l*b;
        System.out.println("Area of rectangle of length "+ l +" and breadth "+ b +" is "+ area);
    }
}