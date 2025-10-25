/*20. Create a class showing an example of default constructor.*/

import java.io.*;

class p20 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter name of the person: ");
        String name = br.readLine();

        System.out.print("Enter age of the person: ");
        int age = Integer.parseInt(br.readLine());

        // Creating Person object using default constructor
        Person p = new Person();

        // Setting values manually since default constructor does not take parameters
        p.setName(name);
        p.setAge(age);

        // Display the details
        p.display();
    }
}

// Class demonstrating default constructor
class Person {
    private String name;
    private int age;

    // Default constructor
    Person() {
        name = "Unknown";   // Default value
        age = 0;            // Default value
        System.out.println("Default constructor called. Initial values set.");
    }

    // Setter methods to manually update values
    void setName(String n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    // Method to display person details
    void display() {
        System.out.println("\nPerson Details:");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}
