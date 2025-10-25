// CODE:-

abstract class Vehicle {
    abstract void startEngine();
    abstract void stopEngine();
}

class Car extends Vehicle {
    void startEngine() {
        System.out.println("Car engine started with key ignition.");
    }

    void stopEngine() {
        System.out.println("Car engine stopped safely.");
    }
}

class Motorcycle extends Vehicle {
    void startEngine() {
        System.out.println("Motorcycle engine started with self-start button.");
    }

    void stopEngine() {
        System.out.println("Motorcycle engine stopped using the kill switch.");
    }
}

class Main {
    public static void main(String[] args) {
        Car c = new Car();
        Motorcycle m = new Motorcycle();

        System.out.println("----- Car -----");
        c.startEngine();
        c.stopEngine();

        System.out.println("\n----- Motorcycle -----");
        m.startEngine();
        m.stopEngine();
    }
}
