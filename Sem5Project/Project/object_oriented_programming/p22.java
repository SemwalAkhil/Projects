/*22. Create a class showing an example of copy constructor.*/

import java.io.*;

class p22 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter name of the employee: ");
        String name = br.readLine();

        System.out.print("Enter employee ID: ");
        int id = Integer.parseInt(br.readLine());

        // Creating Employee object using parameterized constructor
        Employee e1 = new Employee(name, id);

        // Creating another Employee object using copy constructor
        Employee e2 = new Employee(e1);

        System.out.println("\nOriginal Employee:");
        e1.display();

        System.out.println("\nCopied Employee:");
        e2.display();
    }
}

// Class demonstrating copy constructor
class Employee {
    private String name;
    private int id;

    // Parameterized constructor
    Employee(String n, int i) {
        name = n;
        id = i;
        System.out.println("Parameterized constructor called.");
    }

    // Copy constructor
    Employee(Employee e) {
        name = e.name; // Copy name
        id = e.id;     // Copy id
        System.out.println("Copy constructor called.");
    }

    // Method to display employee details
    void display() {
        System.out.println("Name: " + name);
        System.out.println("Employee ID: " + id);
    }
}
