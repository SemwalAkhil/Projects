//Code:-

class Vehicle {
    String make, model, fuel_type;
    int year;

    Vehicle(String make, String model, int year, String fuel_type) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.fuel_type = fuel_type;
    }

    void calculating_Fuel_Efficiency(int distance, int fuel) {
        System.out.println("Fuel efficiency not defined for generic vehicle.");
    }

    void calculating_Distance_traveled(int speed, int time) {
        System.out.println("Distance traveled not defined for generic vehicle.");
    }

    void calculating_Maximum_speed() {
        System.out.println("Maximum speed not defined for generic vehicle.");
    }
}

class Truck extends Vehicle {
    Truck(String make, String model, int year, String fuel_type) {
        super(make, model, year, fuel_type);
    }

    void calculating_Fuel_Efficiency(int distance, int fuel) {
        System.out.println("Truck Fuel Efficiency: " + (distance / fuel) + " km/l");
    }

    void calculating_Distance_traveled(int speed, int time) {
        System.out.println("Truck Distance Traveled: " + (speed * time) + " km");
    }

    void calculating_Maximum_speed() {
        System.out.println("Truck Maximum Speed: 120 km/h");
    }
}

class Car extends Vehicle {
    Car(String make, String model, int year, String fuel_type) {
        super(make, model, year, fuel_type);
    }

    void calculating_Fuel_Efficiency(int distance, int fuel) {
        System.out.println("Car Fuel Efficiency: " + (distance / fuel) + " km/l");
    }

    void calculating_Distance_traveled(int speed, int time) {
        System.out.println("Car Distance Traveled: " + (speed * time) + " km");
    }

    void calculating_Maximum_speed() {
        System.out.println("Car Maximum Speed: 180 km/h");
    }
}

class Motorcycle extends Vehicle {
    Motorcycle(String make, String model, int year, String fuel_type) {
        super(make, model, year, fuel_type);
    }

    void calculating_Fuel_Efficiency(int distance, int fuel) {
        System.out.println("Motorcycle Fuel Efficiency: " + (distance / fuel) + " km/l");
    }

    void calculating_Distance_traveled(int speed, int time) {
        System.out.println("Motorcycle Distance Traveled: " + (speed * time) + " km");
    }

    void calculating_Maximum_speed() {
        System.out.println("Motorcycle Maximum Speed: 150 km/h");
    }
}

class Main {
    public static void main(String[] args) {
        Truck t = new Truck("Tata", "Haulage", 2021, "Diesel");
        Car c = new Car("Maruti", "Swift", 2022, "Petrol");
        Motorcycle m = new Motorcycle("Yamaha", "FZ", 2023, "Petrol");

        System.out.println("----- Truck Details -----");
        t.calculating_Fuel_Efficiency(240, 30);
        t.calculating_Distance_traveled(60, 4);
        t.calculating_Maximum_speed();

        System.out.println("\n----- Car Details -----");
        c.calculating_Fuel_Efficiency(300, 20);
        c.calculating_Distance_traveled(80, 3);
        c.calculating_Maximum_speed();

        System.out.println("\n----- Motorcycle Details -----");
        m.calculating_Fuel_Efficiency(200, 10);
        m.calculating_Distance_traveled(50, 2);
        m.calculating_Maximum_speed();
    }
}
