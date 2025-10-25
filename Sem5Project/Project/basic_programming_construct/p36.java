//36. Java Program to find volume of cuboid
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
        float vol = l*b*h;
        System.out.println("Volume of Cuboid is "+ vol);
    }
}