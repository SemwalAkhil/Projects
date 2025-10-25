/*29. Write a Java program to create a class called Employee with private instance variables
    employee_id, employee_name, and employee_salary. Provide public getter and setter methods 
    to access and modify the id and name variables, but provide a getter method for the salary 
    variable that returns a formatted string without using DecimalFormat.*/

import java.io.*;

class p29 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Create an Employee object
        Employee emp = new Employee();

        // Input and set employee ID
        System.out.print("Enter employee ID: ");
        emp.setId(br.readLine());

        // Input and set employee name
        System.out.print("Enter employee name: ");
        emp.setName(br.readLine());

        // Input and set employee salary
        System.out.print("Enter employee salary: ");
        emp.setSalary(Double.parseDouble(br.readLine()));

        // Display Employee details
        System.out.println("\nEmployee Details:");
        System.out.println("ID: " + emp.getId());
        System.out.println("Name: " + emp.getName());
        System.out.println("Salary: " + emp.getFormattedSalary());
    }
}

// Employee class demonstrating encapsulation with formatted salary getter
class Employee {
    private String employee_id;
    private String employee_name;
    private double employee_salary;

    // Getter and setter for employee ID
    public String getId() {
        return employee_id;
    }

    public void setId(String id) {
        employee_id = id;
    }

    // Getter and setter for employee name
    public String getName() {
        return employee_name;
    }

    public void setName(String name) {
        employee_name = name;
    }

    // Setter for salary
    public void setSalary(double salary) {
        employee_salary = salary;
    }

    // Getter for salary (formatted manually to two decimal places)
    public String getFormattedSalary() {
        return "Rs" + String.format("%.2f", employee_salary);
    }
}
