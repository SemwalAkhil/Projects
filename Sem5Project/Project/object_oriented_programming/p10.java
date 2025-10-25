/*10. Write a Java program to create a class called "Student" with a name, grade, 
    and courses attributes, and methods to add and remove courses (using array).*/

import java.io.*;

class p10 {
    public static void main(String st[]) throws IOException {
        // BufferedReader for reading input from console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read student name
        System.out.print("Enter Student Name: ");
        String name = br.readLine();

        // Read student grade
        System.out.print("Enter Grade: ");
        String grade = br.readLine();

        // Create Student object with name and grade
        Student s1 = new Student(name, grade);

        // Menu-driven program for adding, removing, displaying courses
        while(true) {
            System.out.println("\n1. Add Course\n2. Remove Course\n3. Display Courses\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            if(choice == 1) {
                System.out.print("Enter course to add: ");
                String course = br.readLine();
                s1.addCourse(course);  // Call method to add course
            } else if(choice == 2) {
                System.out.print("Enter course to remove: ");
                String course = br.readLine();
                s1.removeCourse(course);  // Call method to remove course
            } else if(choice == 3) {
                s1.displayCourses();  // Display all enrolled courses
            } else if(choice == 4) {
                System.out.println("Exiting...");
                break;  // Exit the menu loop
            } else {
                System.out.println("Invalid choice!");
            }
        }
    }
}

// Student class using fixed-size array for storing courses
class Student {
    private String name;       // Student's name
    private String grade;      // Student's grade/class
    private String[] courses;  // Array to store course names
    private int courseCount;   // Number of courses currently enrolled

    // Constructor initializes name, grade, and course array
    Student(String n, String g) {
        name = n;
        grade = g;
        courses = new String[10]; // Maximum 10 courses
        courseCount = 0;           // Initially, no courses enrolled
    }

    // Method to add a course
    void addCourse(String course) {
        // Check if max capacity reached
        if(courseCount >= 10) {
            System.out.println("Cannot add more courses. Maximum reached.");
            return;
        }
        // Check if course already exists
        for(int i = 0; i < courseCount; i++) {
            if(courses[i].equalsIgnoreCase(course)) {
                System.out.println(course + " is already enrolled.");
                return;
            }
        }
        // Add course at the next empty index
        courses[courseCount++] = course;
        System.out.println(course + " added.");
    }

    // Method to remove a course
    void removeCourse(String course) {
        boolean found = false;
        for(int i = 0; i < courseCount; i++) {
            if(courses[i].equalsIgnoreCase(course)) {
                // Shift all subsequent courses left to fill the gap
                for(int j = i; j < courseCount - 1; j++) {
                    courses[j] = courses[j + 1];
                }
                courses[--courseCount] = null;  // Reduce count and clear last element
                System.out.println(course + " removed.");
                found = true;
                break;
            }
        }
        if(!found) {
            System.out.println(course + " not found.");
        }
    }

    // Method to display all enrolled courses
    void displayCourses() {
        if(courseCount == 0) {
            System.out.println("No courses enrolled.");
            return;
        }
        System.out.print("Courses enrolled: ");
        for(int i = 0; i < courseCount; i++) {
            System.out.print(courses[i]);
            if(i < courseCount - 1) System.out.print(", ");
        }
        System.out.println(); // New line after listing courses
    }
}
