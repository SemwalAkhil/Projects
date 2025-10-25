/*1. Write a Java program to create a class called "Person" with a name and age attribute. Create two instances of the "Person" class, set their attributes using the constructor, and print their name and age.*/
class p1 {
    public static void main(String st[]) {
        Person p1 = new Person("SURAJ", 19);  // Create first Person object
        Person p2 = new Person("MOHIT", 20); // Create second Person object
        p1.display();  // Display first person's details
        p2.display();  // Display second person's details
    }
}

// Person class with name and age attributes
class Person {
    String name;
    int age;

    // Constructor to initialize name and age
    Person(String nm, int ag) {
        name = nm;
        age = ag;
    }

    // Method to display name and age
    void display() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}
