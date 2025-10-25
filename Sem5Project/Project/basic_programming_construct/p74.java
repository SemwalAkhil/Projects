//74. Write a Java program to replace all the ‘d’ characters with ‘f’ characters
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
            if(str.charAt(i) == 'd')
                st += 'f';
            else
                st += str.charAt(i);
        }
        System.out.println("Replacing all 'd' with 'f' : " + st);
    }
}