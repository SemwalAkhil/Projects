//27. Java program to find area of circle
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius: ");
        float r = sc.nextFloat();
        float area = (22/7.0f)*r*r;
        System.out.println("Area of circle of radius "+ r +" is "+ area);
    }
}