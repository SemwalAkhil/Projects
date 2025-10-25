/*32. Write a Java program to create a class called Student with private instance variables
    student_id, student_name, and grades. Provide public getter and setter methods to access 
    and modify the student_id and student_name variables. Provide a method called addGrade() 
    that allows adding a grade to the grades variable while performing validation.*/

import java.io.*;

class p32 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Create Student object
        Student s = new Student();

        // Input student ID
        System.out.print("Enter student ID: ");
        s.setStudentId(br.readLine());

        // Input student name
        System.out.print("Enter student name: ");
        s.setStudentName(br.readLine());

        // Add grades
        System.out.println("\nEnter 5 grades (0-100):");
        for(int i = 0; i < 5; i++) {
            System.out.print("Grade " + (i+1) + ": ");
            double g = Double.parseDouble(br.readLine());
            s.addGrade(g); // validated addition
        }

        // Display student details and grades
        System.out.println("\nStudent Details:");
        System.out.println("ID: " + s.getStudentId());
        System.out.println("Name: " + s.getStudentName());
        System.out.print("Grades: ");
        s.displayGrades();
    }
}

// Student class demonstrating encapsulation and validated grade addition
class Student {
    private String student_id;
    private String student_name;
    private double[] grades = new double[100]; // max 100 grades
    private int gradeCount = 0;

    // Getter and setter for student_id
    public String getStudentId() {
        return student_id;
    }

    public void setStudentId(String id) {
        student_id = id;
    }

    // Getter and setter for student_name
    public String getStudentName() {
        return student_name;
    }

    public void setStudentName(String name) {
        student_name = name;
    }

    // Method to add a grade with validation
    public void addGrade(double g) {
        if(g < 0 || g > 100) {
            System.out.println("Invalid grade! Must be between 0 and 100.");
            return;
        }
        if(gradeCount >= grades.length) {
            System.out.println("Cannot add more grades, storage full.");
            return;
        }
        grades[gradeCount++] = g;
    }

    // Method to display all grades
    public void displayGrades() {
        for(int i = 0; i < gradeCount; i++) {
            System.out.print(grades[i] + " ");
        }
        System.out.println();
    }
}
