//64. Write a Java program that reads an positive integer and count the number of digits
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        while(true)
        {
            System.out.print("Enter the value: ");
            int n = s.nextInt();
            if(n>0)
            {
                int t = n, i = 0;
                while(t!=0)
                {
                    t /= 10;
                    i++;
                }
                System.out.println("Number of digits in "+ i);
                break;
            }
            else
                System.out.println("Please enter Positive number!\n");

        }
    }
}