// 7. Create a Java program to perform payroll processing using the employee package.

import employee.*;

class p7 {
    public static void main(String args[]) {
        p7_1 e = new p7_1();  // Create object of Emp class from employee package

        e.getDetails();   // Input details
        e.calculatePay(); // Compute salary components
        e.display();      // Print results
    }
}
