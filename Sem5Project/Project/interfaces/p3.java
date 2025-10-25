// 3. Write a Java program to create an interface Flyable with a method called fly_obj(). Create three classes Spacecraft, Airplane, and Helicopter that implement the Flyable interface. Implement the fly_obj() method for each of the three classes.

interface Flyable {
    void fly_obj();
}

class Spacecraft implements Flyable {
    public void fly_obj() {
        System.out.println("Spacecraft is flying in space");
    }
}

class Airplane implements Flyable {
    public void fly_obj() {
        System.out.println("Airplane is flying in the sky");
    }
}

class Helicopter implements Flyable {
    public void fly_obj() {
        System.out.println("Helicopter is flying vertically");
    }
}

public class Main {
    public static void main(String[] args) {
        Flyable s = new Spacecraft();
        Flyable a = new Airplane();
        Flyable h = new Helicopter();

        s.fly_obj();
        a.fly_obj();
        h.fly_obj();
    }
}

/*
Output:
Spacecraft is flying in space
Airplane is flying in the sky
Helicopter is flying vertically
*/
