/*9. Write a Java program to create a class called "Employee" with a name, salary, 
   and hire date attributes, and a method to calculate years of service.*/

import java.util.Date;

class p9 {
    public static void main(String st[]) {
        // Create an Employee object with name, salary, and hire date
        Employee e1 = new Employee("Naman", 56000, "11-12-2000");

        // Print the number of years of service
        System.out.println("Years of service : " + e1.getYearofService());
    } 
}

// Custom exception to handle invalid dates
class NotValidDate extends Throwable {
    NotValidDate(String msg) {
        super(msg);
    }
}
// Utility class for date validation and extraction
class MyDate {
    // Validate the date format and logical correctness
    static void validateDate(String date) throws NotValidDate {
        Date d = new Date();

        // Basic format checks
        if(date.length() != 10) throw new NotValidDate("Exceeds size according to format");
        if(date.charAt(2) != '-' && date.charAt(5) != '-') throw new NotValidDate("'-' not found");

        // Check day, month, year are digits
        if(!(Character.isDigit(date.charAt(0)) && Character.isDigit(date.charAt(1))))
            throw new NotValidDate("Date must be integer");
        if(!(Character.isDigit(date.charAt(3)) && Character.isDigit(date.charAt(4))))
            throw new NotValidDate("Month must be integer");
        if(!(Character.isDigit(date.charAt(6)) && Character.isDigit(date.charAt(7)) && 
             Character.isDigit(date.charAt(8)) && Character.isDigit(date.charAt(9))))
            throw new NotValidDate("Year must be integer");

        // Extract numeric day, month, year
        int dt = (date.charAt(0) - '0') * 10 + (date.charAt(1) - '0');
        int month = (date.charAt(3) - '0') * 10 + (date.charAt(4) - '0');
        int year = (date.charAt(6) - '0') * 1000 + (date.charAt(7) - '0') * 100 +
                   (date.charAt(8) - '0') * 10 + (date.charAt(9) - '0');

        // Logical validation
        if(dt > 31) throw new NotValidDate("Date Invalid");
        if(month > 12) throw new NotValidDate("Month Invalid");

        // Future date check
        if(year > 1900 + d.getYear() || 
           (year == 1900 + d.getYear() && month > d.getMonth() + 1) ||
           (year == 1900 + d.getYear() && month == d.getMonth() + 1 && dt > d.getDate()))
            throw new NotValidDate("Future Dates are not allowed");
    }
    // Extract year from date string
    static int getYear(String date) {
        return ((date.charAt(6) - '0') * 1000 + (date.charAt(7) - '0') * 100 +
                (date.charAt(8) - '0') * 10 + (date.charAt(9) - '0'));
    }
    // Extract month from date string
    static int getMonth(String date) {
        return (date.charAt(3) - '0') * 10 + (date.charAt(4) - '0');
    }
    // Extract day from date string
    static int getDate(String date) {
        return (date.charAt(0) - '0') * 10 + (date.charAt(1) - '0');
    }
}

// Employee class with name, salary, hire date and method to compute years of service
class Employee {
    String name;
    double salary;
    String hireDate;
    // Constructor validates date before initializing employee
    Employee(String nm, double sal, String hdate) {
        try {
            MyDate.validateDate(hdate);
        } catch(NotValidDate e) {
            System.out.println(e.getMessage());
            System.exit(0); // Stop program if invalid date
        }
        name = nm;
        salary = sal;
        hireDate = hdate;
    }
    // Calculate years of service based on current date
    int getYearofService() {
        Date d = new Date();
        int yearDiff = d.getYear() + 1900 - MyDate.getYear(hireDate);
        int monthDiff = (d.getMonth() + 1) - MyDate.getMonth(hireDate);
        int dayDiff = d.getDate() - MyDate.getDate(hireDate);

        // Adjust year if current month/day is before hire month/day
        if(monthDiff < 0 || (monthDiff == 0 && dayDiff < 0)) yearDiff--;
        return yearDiff;
    }
}
