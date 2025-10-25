//33. Java Program to find area of Prism
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the height of prism: ");
        float h = sc.nextFloat();
        System.out.print("Enter the 1st side of triangular part: ");
        float s1 = sc.nextFloat();
        System.out.print("Enter the 2nd side of triangular part: ");
        float s2 = sc.nextFloat();
        System.out.print("Enter the 3rd side (base) of triangular part: ");
        float s3 = sc.nextFloat();
        System.out.print("Enter the height of triangular part: ");
        float b = sc.nextFloat();
        float area = ((s1+s2+s3)*h + s3*b);
        System.out.println("Total Surface Area of Prism is "+ area);
    }
}