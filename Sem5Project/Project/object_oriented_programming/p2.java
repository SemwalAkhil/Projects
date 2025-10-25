/*2. Write a Java program to create a class called "Dog" with a name and breed attribute. Create two instances of the "Dog" class, set their attributes using the constructor and modify the attributes using the setter methods and print the updated values.*/
class p2 {
    public static void main(String st[]) {
        // Create two Dog objects using constructor
        Dog d1 = new Dog("Tom", "Labrador Retriever");
        Dog d2 = new Dog("Rock", "German Shepherd");
        System.out.println("Values using constructor:");
        d1.display();
        d2.display();
        // Modify attributes using setter method
        d1.setter("Thomas", "Golden Retriever");
        d2.setter("Rocket", "Rottweiler");
        System.out.println("Values after modification using setter:");
        d1.display();
        d2.display();
    }
}

// Dog class with name and breed attributes
class Dog {
    String name;
    String breed;
    // Constructor to initialize name and breed
    Dog(String nm, String bd) {
        name = nm;
        breed = bd;
    }
    // Setter method to modify name and breed
    void setter(String nm, String bd) {
        name = nm;
        breed = bd;
    }
    // Method to display name and breed
    void display() {
        System.out.println("Name: " + name + ", Breed: " + breed);
    }
}
