// CODE:-

class Animal {
    String name = "Animal";

    void display() {
        System.out.println("This is the Animal class");
    }
}

class Dog extends Animal {
    String name = "Dog";

    void display() {
        System.out.println("This is the Dog class");
    }

    void showDetails() {
        System.out.println("Child class name: " + name);          // refers to Dog's name
        System.out.println("Parent class name: " + super.name);   // refers to Animal's name
        super.display();  // calling parent class method using super
    }
}

class Main {
    public static void main(String[] args) {
        Dog obj = new Dog();
        obj.showDetails();
    }
}