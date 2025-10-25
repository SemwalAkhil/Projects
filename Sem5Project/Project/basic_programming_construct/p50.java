//50. Java Pogram To Find Distance Between Two Points
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Coordinates of 1st point (x1,y1): ");
        int x = sc.nextInt(), y = sc.nextInt();
        System.out.print("Enter the Coordinates of 2nd point (x2,y2): ");
        x -= sc.nextInt();
        y -= sc.nextInt();
        double d = Math.sqrt(x*x+y*y);
        System.out.println("Distance between given points is "+ d);
    }
}