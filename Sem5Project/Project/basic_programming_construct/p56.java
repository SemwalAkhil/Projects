//56. Write a Java program that takes a year from user and print whether that year is a leap year or not
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            System.out.print("Enter the year in numbers: ");
            int year = sc.nextInt();
            if(year > 0)
            {
                if(year%4 == 0)
                    System.out.println("Year "+ year +" is a Leap Year!");
                    else
                    System.out.println("Year "+ year +" is not a Leap Year!");
                break;
            }
            else
                System.out.println("Please enter valid Year!\n");
        }
               
    }
}