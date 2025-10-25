//79. Write a java program to reverse a string
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the String: ");
        String st = "", str = s.next();
        for(int i = str.length()-1; i >=0 ;i--)
                st += str.charAt(i);
        System.out.println("Reversed String: " + st);
    }
}