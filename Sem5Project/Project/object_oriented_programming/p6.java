/*6. Write a Java program to create a class called "Employee" 
with a name, job title, and salary attributes, and methods to calculate and update salary.*/
class p6{
    public static void main(String ar[]){
        // Create an Employee object with initial details
        Employee e1 = new Employee("Naman","Software Engineer",55000);
        // Update salary by adding increment
        e1.updateSalary(5000);
        // Calculate and print annual salary
        System.out.println("Annual salary of employee : "+e1.calculateSalary());
    }
}
// Class representing an Employee
class Employee{
    String name;       // Employee's name
    String job_title;  // Employee's job title
    int salary;        // Employee's monthly salary
    // Constructor to initialize attributes
    Employee(String nm,String jt,int slry){
        name=nm;
        job_title=jt;
        salary=slry;
    }
    // Method to update salary (increment)
    void updateSalary(int incre){
        salary = salary + incre;
        System.out.println("Salary after updating : "+salary);
    }
    // Method to calculate annual salary
    int calculateSalary(){
        return salary * 12;
    }
}
