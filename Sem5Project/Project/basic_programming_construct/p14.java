//14. Write a Java program that accepts an integer (n) and computes the value of n+nn+nnn
import java.io.*;

class Main
{
    public static void main(String args[])
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try
        {
            System.out.print("Enter the value of n: ");
            int n = Integer.parseInt(br.readLine());
            System.out.println("The value of n + nn + nnn : " + (n + (n*n) + (n*n*n)));
        }
        catch(Exception e){
            System.out.println("Please enter valid number!");
        }
    }
}
