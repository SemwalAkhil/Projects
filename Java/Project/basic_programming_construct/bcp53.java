import java.util.*;

// 53. Write a Java program to find the number of days in a month
public class bcp53 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter month (1-12) : ");
        int month = scanner.nextInt();
        int year = 0;
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                System.out.println("31 days");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                System.out.println("30 days");
                break;
            case 2:
                System.out.print("Enter year : ");
                year = scanner.nextInt();
                if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)) {
                    System.out.println("29 days");
                } else {
                    System.out.println("28 days");
                }
                break;
                
            default:
                break;
        }
        scanner.close();
    }
}
