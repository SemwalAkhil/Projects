import java.util.Scanner;

public class LeapYearCheck {
    static boolean isLeapYear(int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        if (year % 4 == 0) return true;
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter year: ");
        int year = sc.nextInt();

        if (isLeapYear(year))
            System.out.println(year + " is a leap year.");
        else
            System.out.println(year + " is not a leap year.");
        sc.close();
    }
}
output:-
        Enter year: 2024
        2024 is a leap year.
        