/*21. Create a class showing an example of parameterized constructor.*/

import java.io.*;

class p21 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter name of the student: ");
        String name = br.readLine();

        System.out.print("Enter roll number of the student: ");
        int roll = Integer.parseInt(br.readLine());

        // Creating Student object using parameterized constructor
        Student s = new Student(name, roll);

        // Display the student details
        s.display();
    }
}

// Class demonstrating parameterized constructor
class Student {
    private String name;
    private int roll;

    // Parameterized constructor
    Student(String n, int r) {
        name = n; // Initialize name
        roll = r; // Initialize roll number
        System.out.println("Parameterized constructor called. Values initialized.");
    }

    // Method to display student details
    void display() {
        System.out.println("\nStudent Details:");
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + roll);
    }
}
