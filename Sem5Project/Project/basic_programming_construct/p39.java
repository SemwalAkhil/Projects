//39. Java program to find surface area of cylinder
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius: ");
        float r = sc.nextFloat();
        System.out.print("Enter the height: ");
        float h = sc.nextFloat();
        float tsa = 2*(22.0f/7)*r*(r+h);
        float lsa = 2*(22.0f/7)*r*h;
        System.out.println("Total Surface Area of Cylinder is "+ tsa);
        System.out.println("Curved Surface Area of Cylinder is "+ lsa);
    }
}