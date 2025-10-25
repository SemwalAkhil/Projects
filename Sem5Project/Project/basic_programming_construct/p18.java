//18. Write a Java program to convert a string to an integer
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the Integer: ");
        String str = s.next();
        int x = 0, i = 0, l = str.length();
        while(i != l)
        {
            char c = str.charAt(i);
            if(c <'0' || c > '9')
                break;
            x = x*10 + (c-'0');
            i++;
        }
        if(i == l){
            System.out.println("Your Integer Number: "+ x);
        }else{
            System.out.println("Please Enter valid Integer!");
        }
    }
}