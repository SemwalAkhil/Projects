//10. Write a Java program and compute the sum of the digits of an integer
import java.io.*;

class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the value: ");
        int y = Integer.parseInt(br.readLine());
        int sum = 0, x = y;
        while(x!=0){
            sum += x%10;
            x /= 10;
        }
        System.out.println("Sum of all digits of " + y + " is "+sum);
    }
}