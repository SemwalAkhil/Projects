/*23. Create a class entering the roll number, name, and class of the student from user 
    but roll number should be automatically generated for 10 students.*/

import java.io.*;

class p23 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Student[] students = new Student[10]; // Array to store 10 students

        for(int i = 0; i < 10; i++) {
            System.out.println("\nEnter details for Student " + (i + 1) + ":");

            System.out.print("Enter name: ");
            String name = br.readLine();

            System.out.print("Enter class: ");
            String cls = br.readLine();

            // Create student object; roll number is automatically assigned
            students[i] = new Student(name, cls);
        }

        // Display all students
        System.out.println("\nStudent Details:");
        for(int i = 0; i < 10; i++) {
            students[i].display();
        }
    }
}

// Student class with automatic roll number generation
class Student {
    private static int nextRoll = 1; // Static counter for roll numbers
    private int rollNo;
    private String name;
    private String cls;

    // Parameterized constructor; roll number is assigned automatically
    Student(String n, String c) {
        name = n;
        cls = c;
        rollNo = nextRoll++; // Assign current roll number and increment for next student
    }

    // Method to display student details
    void display() {
        System.out.println("Roll No: " + rollNo + " | Name: " + name + " | Class: " + cls);
    }
}
