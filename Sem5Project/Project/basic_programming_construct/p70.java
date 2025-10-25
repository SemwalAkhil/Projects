// 70. Write a Java program to convert all characters in a string to lowercase
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the String: ");
        String st = "", str = s.next();
        for(int i = 0,l = str.length(); i < l;i ++)
        {
            if(str.charAt(i) >= 'A' && str.charAt(i)<='Z')
                st += (char)(str.charAt(i) + 32);
            else
                st += str.charAt(i);
        }
        System.out.println("LowerCase String: " + st);
    }
}