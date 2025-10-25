// 2. Create a Java program to access the java.util.Date class through qualified way and print the current date of the system.

class p2 {
    public static void main(String args[]) {
        // Create Date object using fully qualified class name
        java.util.Date currentDate = new java.util.Date();

        // Print the current system date
        System.out.println("Current Date: " + currentDate);
    }
}
