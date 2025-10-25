//80. Write a java program to remove html tags from a string
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the String: ");
        String st = "", str = s.nextLine();
        for(int i = 0,l = str.length(); i < l;i++)
        {
            if(str.charAt(i) == '<')
            {
                int j = i;
                while(j <str.length() && str.charAt(j) != '>')
                    j++;
                if(j<str.length())
                    i = j;
            }
            else
                st += str.charAt(i);
        }
        System.out.println("String without HTML tags: " + st);
    }
}