//26. Write a Java program to add all the digits of a given positive integer
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int sum = 0, n = s.nextInt();
        while(n>0){
            sum += n%10;
            n = n/10;
        }
        System.out.println("Sum of all Digit is "+ sum);
    }
}