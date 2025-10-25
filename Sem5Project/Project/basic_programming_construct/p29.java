//27. Java program to find area of circle
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
        float area = 0.5f*b*h;
        System.out.println("Area of Triangle of base "+ b +" and height "+ h +" is "+ area);
    }
}