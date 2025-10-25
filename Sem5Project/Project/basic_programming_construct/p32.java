//32. Java Program to find area of parallelogram
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the base: ");
        float b = sc.nextFloat();
        System.out.print("Enter the height: ");
        float h = sc.nextFloat();
        float area = b*h;
        System.out.println("Area of parallelogram of base "+ b +" and height "+ h +" is "+ area);
    }
}