//75. Write a java program to get the length of a given string
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String str = s.next();
        System.out.println("Length of String: " + str.length());
    }
}