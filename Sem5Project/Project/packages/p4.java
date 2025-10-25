// 4. Create a Java program to access the java.util.Date class through qualified way and print the current date of the system but inherit the Date class.

class p4 extends java.util.Date {
    public static void main(String args[]) {
        // Create object of subclass (p4) which inherits java.util.Date
        p4 currentDate = new p4();

        // Print the current system date
        System.out.println("Current Date: " + currentDate);
    }
}
