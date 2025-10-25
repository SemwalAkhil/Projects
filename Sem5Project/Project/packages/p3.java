// 3. Create a Java program to access the java.util.Date class through import keyword and print the current date of the system but inherit the Date class.

import java.util.Date;

class p3 extends Date {
    public static void main(String args[]) {
        // Create object of subclass (p3) which inherits Date
        p3 currentDate = new p3();

        // Print the current system date
        System.out.println("Current Date: " + currentDate);
    }
}
