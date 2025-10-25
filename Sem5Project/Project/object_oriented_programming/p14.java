/*14. Write a Java program to create a class called "School" with attributes for students,
    teachers, and classes, and methods to add and remove students and teachers, and to create classes.*/

import java.io.*;

class p14 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        School school = new School(); // Create School object

        while(true) {
            System.out.println("\n1. Add Student\n2. Remove Student\n3. Add Teacher\n4. Remove Teacher\n5. Create Class\n6. Display School Info\n7. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            switch(choice) {
                case 1:
                    System.out.print("Enter student name: ");
                    String studentName = br.readLine();
                    school.addStudent(studentName);
                    break;
                case 2:
                    System.out.print("Enter student name to remove: ");
                    String removeStudent = br.readLine();
                    school.removeStudent(removeStudent);
                    break;
                case 3:
                    System.out.print("Enter teacher name: ");
                    String teacherName = br.readLine();
                    school.addTeacher(teacherName);
                    break;
                case 4:
                    System.out.print("Enter teacher name to remove: ");
                    String removeTeacher = br.readLine();
                    school.removeTeacher(removeTeacher);
                    break;
                case 5:
                    System.out.print("Enter class name: ");
                    String className = br.readLine();
                    school.createClass(className);
                    break;
                case 6:
                    school.displaySchoolInfo();
                    break;
                case 7:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}

// School class managing students, teachers, and classes using arrays
class School {
    private String[] students;
    private String[] teachers;
    private String[] classes;
    private int studentCount;
    private int teacherCount;
    private int classCount;

    School() {
        students = new String[50]; // Maximum 50 students
        teachers = new String[20]; // Maximum 20 teachers
        classes = new String[10];  // Maximum 10 classes
        studentCount = teacherCount = classCount = 0;
    }

    // Add student to school
    void addStudent(String name) {
        if(studentCount >= 50) {
            System.out.println("Cannot add more students. Limit reached.");
            return;
        }
        students[studentCount++] = name;
        System.out.println(name + " added as a student.");
    }

    // Remove student from school
    void removeStudent(String name) {
        boolean found = false;
        for(int i = 0; i < studentCount; i++) {
            if(students[i].equalsIgnoreCase(name)) {
                for(int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                students[--studentCount] = null;
                System.out.println(name + " removed from students.");
                found = true;
                break;
            }
        }
        if(!found) {
            System.out.println(name + " not found among students.");
        }
    }

    // Add teacher to school
    void addTeacher(String name) {
        if(teacherCount >= 20) {
            System.out.println("Cannot add more teachers. Limit reached.");
            return;
        }
        teachers[teacherCount++] = name;
        System.out.println(name + " added as a teacher.");
    }

    // Remove teacher from school
    void removeTeacher(String name) {
        boolean found = false;
        for(int i = 0; i < teacherCount; i++) {
            if(teachers[i].equalsIgnoreCase(name)) {
                for(int j = i; j < teacherCount - 1; j++) {
                    teachers[j] = teachers[j + 1];
                }
                teachers[--teacherCount] = null;
                System.out.println(name + " removed from teachers.");
                found = true;
                break;
            }
        }
        if(!found) {
            System.out.println(name + " not found among teachers.");
        }
    }

    // Create a new class
    void createClass(String className) {
        if(classCount >= 10) {
            System.out.println("Cannot create more classes. Limit reached.");
            return;
        }
        classes[classCount++] = className;
        System.out.println("Class " + className + " created.");
    }

    // Display all students, teachers, and classes
    void displaySchoolInfo() {
        System.out.println("\n--- School Information ---");
        System.out.print("Students: ");
        if(studentCount == 0) System.out.print("None");
        for(int i = 0; i < studentCount; i++) {
            System.out.print(students[i]);
            if(i < studentCount - 1) System.out.print(", ");
        }
        System.out.println();

        System.out.print("Teachers: ");
        if(teacherCount == 0) System.out.print("None");
        for(int i = 0; i < teacherCount; i++) {
            System.out.print(teachers[i]);
            if(i < teacherCount - 1) System.out.print(", ");
        }
        System.out.println();

        System.out.print("Classes: ");
        if(classCount == 0) System.out.print("None");
        for(int i = 0; i < classCount; i++) {
            System.out.print(classes[i]);
            if(i < classCount - 1) System.out.print(", ");
        }
        System.out.println("\n--------------------------");
    }
}
