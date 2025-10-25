// 72. Write a Java program to trim a string(remove whitespaces)
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String str = (s.nextLine()).trim();
        System.out.println("Trimmed String: " + str);
    }
}