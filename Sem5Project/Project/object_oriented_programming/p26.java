/*26. Write a Java program to create a class called Person with private instance variables
    name, age, and country. Provide public getter and setter methods to access and modify these variables.*/

import java.io.*;

class p26 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Create a Person object
        Person p = new Person();

        // Input and set name
        System.out.print("Enter name: ");
        p.setName(br.readLine());

        // Input and set age
        System.out.print("Enter age: ");
        p.setAge(Integer.parseInt(br.readLine()));

        // Input and set country
        System.out.print("Enter country: ");
        p.setCountry(br.readLine());

        // Display Person details using getters
        System.out.println("\nPerson Details:");
        System.out.println("Name: " + p.getName());
        System.out.println("Age: " + p.getAge());
        System.out.println("Country: " + p.getCountry());
    }
}

// Person class demonstrating encapsulation
class Person {
    private String name;
    private int age;
    private String country;

    // Getter for name
    public String getName() {
        return name;
    }

    // Setter for name
    public void setName(String n) {
        name = n;
    }

    // Getter for age
    public int getAge() {
        return age;
    }

    // Setter for age
    public void setAge(int a) {
        age = a;
    }

    // Getter for country
    public String getCountry() {
        return country;
    }

    // Setter for country
    public void setCountry(String c) {
        country = c;
    }
}
