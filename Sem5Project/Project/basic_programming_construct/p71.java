// 71. Write a Java program to convert all characters in a string to uppercase
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String st = "", str = s.next();
        for(int i = 0,l = str.length(); i < l;i ++)
        {
            if(str.charAt(i) >= 'a' && str.charAt(i)<='z')
                st += (char)(str.charAt(i) - 32);
            else
                st += str.charAt(i);
        }
        System.out.println("UpperCase String: " + st);
    }
}