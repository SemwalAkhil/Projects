// 7.1. Create a package 'employee' containing class Emp for payroll processing.

package employee;

import java.util.Scanner;

// Use same class name as file name
public class p7_1 {
    String name, empid, category;
    double bpay, hra, da, npay, pf, grosspay, incometax, allowance;

    // Method to input employee details
    public void getDetails() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Employee Name: ");
        name = sc.nextLine();

        System.out.print("Enter Employee ID: ");
        empid = sc.nextLine();

        System.out.print("Enter Employee Category: ");
        category = sc.nextLine();

        System.out.print("Enter Basic Pay: ");
        bpay = sc.nextDouble();

        sc.close();
    }

    // Method to calculate salary components
    public void calculatePay() {
        hra = 0.15 * bpay;
        da = 0.10 * bpay;
        allowance = 0.05 * bpay;
        grosspay = bpay + hra + da + allowance;
        pf = 0.12 * grosspay;
        incometax = 0.10 * grosspay;
        npay = grosspay - (pf + incometax);
    }

    // Method to display results
    public void display() {
        System.out.println("\n---------- EMPLOYEE PAY SLIP ----------");
        System.out.println("Employee Name     : " + name);
        System.out.println("Employee ID       : " + empid);
        System.out.println("Category          : " + category);
        System.out.println("---------------------------------------");
        System.out.println("Basic Pay         : " + bpay);
        System.out.println("HRA (15%)         : " + hra);
        System.out.println("DA (10%)          : " + da);
        System.out.println("Allowance (5%)    : " + allowance);
        System.out.println("Gross Pay         : " + grosspay);
        System.out.println("PF (12%)          : " + pf);
        System.out.println("Income Tax (10%)  : " + incometax);
        System.out.println("---------------------------------------");
        System.out.println("Net Pay           : " + npay);
        System.out.println("---------------------------------------");
    }
}
