//44. Java program to find factorial of any number
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            System.out.print("Enter the number: ");
            int n = sc.nextInt();
            if(n >= 0){
                int s = n, fact = 1;
                while(s>0){
                    fact *= s;
                    s--;
                }
                System.out.println("Factorial of number "+ n +" is "+ fact);
                break;
            }
            else{
                System.out.println("Please enter positive number!\n");
            }
        }
    }
}