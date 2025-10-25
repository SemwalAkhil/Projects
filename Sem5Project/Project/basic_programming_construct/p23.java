//23. Write a Java program to compute the square root of an given 
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int i=0,n = s.nextInt();
        if(n>=0){
            while((i*i)<=n)
                i++;
            System.out.print("Square root of "+ n +" is "+ (i-1));
        }
        else{
            System.out.println("Enter positive value!");
        }
    }
}