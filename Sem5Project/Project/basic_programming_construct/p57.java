//57. Write a Java program to input 5 numbers from keyboard and find their sum and average
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter all the five values: ");
        int x1 = s.nextInt();
        int x2 = s.nextInt();
        int x3 = s.nextInt();
        int x4 = s.nextInt();
        int x5 = s.nextInt();
        System.out.println("Sum: "+ (x1+x2+x3+x4+x5));
        System.out.println("Average: "+ (x1+x2+x3+x4+x5)/5);
    }
}