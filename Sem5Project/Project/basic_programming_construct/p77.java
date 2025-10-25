//77. Write a Java program to get the character at the given index within the String
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the String: ");
        String str = s.next();
        System.out.print("Enter the index: ");
        int i = s.nextInt();
        if(i >=0 && i < str.length())
            System.out.println("Character at index " + i + " in String: " + str.charAt(i));
        else
            System.out.println("Please enter valid Index!");
     }
}