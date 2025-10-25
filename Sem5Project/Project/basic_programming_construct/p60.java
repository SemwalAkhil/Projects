//60. Write a Java program to display the cube of the number upto given an integer
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value: ");
        int n = s.nextInt();
        System.out.println("Cube of number "+ n +" : "+ (n*n*n));
    }
}
