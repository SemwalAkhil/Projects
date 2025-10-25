//37. Java Program to find volume of cone
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
        float vol = (1/3.0f)*(22.0f/7)*r*r*h;
        System.out.println("Volume of Cone of radius "+ r +" and height "+ h +" is "+ vol);
    }
}