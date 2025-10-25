//53. Write a Java program to find the number of days in a month
import java.util.Scanner;

class Main
{
    public static void main (String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the month: ");
        String month = s.next().toLowerCase();
        switch(month)
        {
            case "january": case "march": case "may": case "july": case "august": case "october" : case "december":
                System.out.println("No. of days in "+ month +" is 31");
                break;
            case "februrary": 
                System.out.println("No. of days in "+ month +" is 28(for Non Leap Year) or 29(for Leap Year");
                break;
            case "april": case "june": case "september": case "november":
                System.out.println("No. of days in "+ month +" is 30");
                break;
            default: 
                System.out.println("Please enter Valid month!");
        }
    }
}