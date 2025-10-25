//55. Write a Java Program to accept number of week’s day (1-7) and print name of the day
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the week's day (1-7): ");
        int day = sc.nextInt();
        switch(day)
        {
            case 1: System.out.println("It's Sunday!");
                    break;
            case 2: System.out.println("It's Monday!");
                    break;
            case 3: System.out.println("It's Tuesday!");
                    break;
            case 4: System.out.println("It's Wednesday!");
                    break;
            case 5: System.out.println("It's Thursday!");
                    break;
            case 6: System.out.println("It's Friday!");
                    break;
            case 7: System.out.println("It's Saturday!");
                    break;
            default: System.out.println("Please Enter valid day!");
        }
        
    }
}