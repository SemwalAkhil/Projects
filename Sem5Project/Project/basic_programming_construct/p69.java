// 69. Write a Java program to concatenate two string
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the 1st String: ");
        String s1 = s.next();
        System.out.print("Enter the 2nd String: ");
        s1 = s1 + (s.next());
        System.out.println("Concatenated String: " + s1);
    }
}