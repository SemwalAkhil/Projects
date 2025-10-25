//24. Write a Java program to check if a positive number is a palindrome or not
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int i=0,n = s.nextInt(),temp = n,rev = 0;
        if(n>=0){
            while(temp!=0){
                rev = rev*10 + temp%10;
                temp = temp / 10;
            }
            if(rev == n)
                System.out.print("Number is Pallindrome!");
            else
                System.out.print("Number is not Pallindrome!");
        }
        else{
            System.out.println("Enter positive value!");
        }
    }
}