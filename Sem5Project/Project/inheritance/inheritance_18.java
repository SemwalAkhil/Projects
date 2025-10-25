// CODE:-

abstract class Animal {
    abstract void eat();
    abstract void sleep();
}

class Lion extends Animal {
    void eat() {
        System.out.println("Lion eats meat and hunts for food.");
    }

    void sleep() {
        System.out.println("Lion sleeps for around 20 hours a day.");
    }
}

class Tiger extends Animal {
    void eat() {
        System.out.println("Tiger eats flesh and prefers to hunt alone.");
    }

    void sleep() {
        System.out.println("Tiger sleeps for about 16 hours a day.");
    }
}

class Deer extends Animal {
    void eat() {
        System.out.println("Deer eats grass, leaves, and plants.");
    }

    void sleep() {
        System.out.println("Deer sleeps lightly to stay alert from predators.");
    }
}

class Main {
    public static void main(String[] args) {
        Lion l = new Lion();
        Tiger t = new Tiger();
        Deer d = new Deer();

        System.out.println("----- Lion Behavior -----");
        l.eat();
        l.sleep();

        System.out.println("\n----- Tiger Behavior -----");
        t.eat();
        t.sleep();

        System.out.println("\n----- Deer Behavior -----");
        d.eat();
        d.sleep();
    }
}
