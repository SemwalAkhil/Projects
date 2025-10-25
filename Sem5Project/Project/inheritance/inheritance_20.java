// CODE:-

abstract class Shape3D {
    abstract double calculateVolume();
    abstract double calculateSurfaceArea();
}

class Sphere extends Shape3D {
    double radius;

    Sphere(double radius) {
        this.radius = radius;
    }

    double calculateVolume() {
        return (4.0 / 3.0) * 3.14 * radius * radius * radius;
    }

    double calculateSurfaceArea() {
        return 4 * 3.14 * radius * radius;
    }
}

class Cube extends Shape3D {
    double side;

    Cube(double side) {
        this.side = side;
    }

    double calculateVolume() {
        return side * side * side;
    }

    double calculateSurfaceArea() {
        return 6 * side * side;
    }
}

class Main {
    public static void main(String[] args) {
        Sphere s = new Sphere(5);
        Cube c = new Cube(4);

        System.out.println("----- Sphere Details -----");
        System.out.println("Volume of Sphere: " + s.calculateVolume());
        System.out.println("Surface Area of Sphere: " + s.calculateSurfaceArea());

        System.out.println("\n----- Cube Details -----");
        System.out.println("Volume of Cube: " + c.calculateVolume());
        System.out.println("Surface Area of Cube: " + c.calculateSurfaceArea());
    }
}
