//30. Java Program to find area of equilateral triangle
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the side: ");
        float s = sc.nextFloat();
        float area = 1.732f/4*s*s;
        System.out.println("Area of Equilateral Triangle of side is "+ area);
    }
}