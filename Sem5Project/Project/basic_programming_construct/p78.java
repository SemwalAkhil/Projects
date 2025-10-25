//78. Write a java program to remove a particular character from a string
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String st = "", str = s.next();
        System.out.print("Enter the character to be removed: ");
        char c = s.next().charAt(0);
        for(int i = 0,l = str.length(); i < l;i ++)
        {
            if(str.charAt(i) != c)
                st += str.charAt(i);
        }
        System.out.println("Removing '"+ c +"' from String: " + st);
    }
}