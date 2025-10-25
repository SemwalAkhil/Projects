//40. Java program to find surface area of cube
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the side: ");
        float s = sc.nextFloat();
        float tsa = 6.0f*s*s;
        float lsa = 4.0f*s*s;
        System.out.println("Total Surface Area of Cube is "+ tsa);
        System.out.println("Curved Surface Area of Cube is "+ lsa);
    }
}