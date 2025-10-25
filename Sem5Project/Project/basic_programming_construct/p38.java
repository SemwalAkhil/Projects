//38. Java program to find surface area of cuboid
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
        System.out.print("Enter the height: ");
        float h = sc.nextFloat();
        float tsa = 2*(l*b + b*h + h*l);
        float lsa = 2*(l+b)*h;
        System.out.println("Total Surface Area of Cuboid is "+ tsa);
        System.out.println("Curved Surface Area of Cuboid is "+ lsa);
    }
}