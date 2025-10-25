// CODE:-

abstract class Bird {
    abstract void fly();
    abstract void makeSound();
}

class Eagle extends Bird {
    void fly() {
        System.out.println("Eagle flies high with strong wings.");
    }

    void makeSound() {
        System.out.println("Eagle screeches loudly.");
    }
}

class Hawk extends Bird {
    void fly() {
        System.out.println("Hawk soars swiftly and dives to catch prey.");
    }

    void makeSound() {
        System.out.println("Hawk makes a sharp, piercing cry.");
    }
}

class Main {
    public static void main(String[] args) {
        Eagle e = new Eagle();
        Hawk h = new Hawk();

        System.out.println("----- Eagle -----");
        e.fly();
        e.makeSound();

        System.out.println("\n----- Hawk -----");
        h.fly();
        h.makeSound();
    }
}
