//68. Write a Java program to create a simple calculator
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        while(true)
        {
            Scanner sc = new Scanner(System.in);
            System.out.print("<-------- CALCULATOR -----–->");
            System.out.print("Press -> 1 For ADDITION");
            System.out.print("Press -> 2 For SUBTRACTION"); 
            System.out.print("Press -> 3 For MULTIPLICATION");
            System.out.print("Press -> 4 For DIVISION");
            System.out.print("Press -> 5 For EXPONENTIAL");
            System.out.print("Press -> 6 For EXIT");
            System.out.print("What do you want to do ? ");
            int n = sc.nextInt();
            if(n>=1 && n<=5)
            {
                System.out.println("Enter ther 1st number: ");
                int a = sc.nextInt(); 
                System.out.println("Enter ther 2nd number: ");
                int b = sc.nextInt(); 
                if (n == 1)
                    System.out.println("\nAddition of " + a + " and " + b + " is " + (a + b));
                else if (n == 2)
                    System.out.println("\nSubtraction of " + a + " by " + b + " is " + (a - b));
                else if (n == 3)
                    System.out.println("\nMultiplication of " + a + " by " + b + " is " + (a * b));
                else if (n == 4)
                    System.out.println("\nDivision of " + a + " by " + b + " is " + (a / b));
                else
                    System.out.println("\nPower of " + a + " raised to " + b + " is " + Math.pow(a,b));

            }
            }
            if (per >= 0 && per <= 100)
            {
                if (per > 80)
                System.out.println("\nYour Percentile is "+ per +" and Grade is A");
                else if (per > 60)
                System.out.println("\nYour Percentile is "+ per +" and Grade is B");
                else if (per > 40)
                System.out.println("\nYour Percentile is "+ per +" and Grade is C");
                else
                System.out.println("\nYour Percentile is "+ per +" and Grade is D");
            }
        }
    }
}