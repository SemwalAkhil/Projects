/*16. Write a Java program to create a class called "Shape" with abstract methods for 
    calculating area and perimeter, and subclasses for "Rectangle", "Circle", and "Triangle".*/

import java.io.*;

abstract class Shape {
    // Abstract methods for area and perimeter
    abstract double area();
    abstract double perimeter();
}

// Rectangle subclass
class Rectangle extends Shape {
    private double length;
    private double width;

    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Override area method
    double area() {
        return length * width;
    }

    // Override perimeter method
    double perimeter() {
        return 2 * (length + width);
    }
}

// Circle subclass
class Circle extends Shape {
    private double radius;

    Circle(double r) {
        radius = r;
    }

    // Override area method
    double area() {
        return Math.PI * radius * radius;
    }

    // Override perimeter method
    double perimeter() {
        return 2 * Math.PI * radius;
    }
}

// Triangle subclass
class Triangle extends Shape {
    private double a, b, c; // sides of triangle

    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    // Override area method using Heron's formula
    double area() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Override perimeter method
    double perimeter() {
        return a + b + c;
    }
}

// Main class to demonstrate shapes
class p16 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Rectangle input
        System.out.print("Enter length of rectangle: ");
        double l = Double.parseDouble(br.readLine());
        System.out.print("Enter width of rectangle: ");
        double w = Double.parseDouble(br.readLine());
        Rectangle rect = new Rectangle(l, w);

        // Circle input
        System.out.print("Enter radius of circle: ");
        double r = Double.parseDouble(br.readLine());
        Circle circ = new Circle(r);

        // Triangle input
        System.out.print("Enter sides of triangle (a b c): ");
        String[] sides = br.readLine().split(" ");
        double a = Double.parseDouble(sides[0]);
        double b = Double.parseDouble(sides[1]);
        double c = Double.parseDouble(sides[2]);
        Triangle tri = new Triangle(a, b, c);

        // Display areas and perimeters
        System.out.println("\nRectangle -> Area: " + rect.area() + ", Perimeter: " + rect.perimeter());
        System.out.println("Circle -> Area: " + circ.area() + ", Perimeter: " + circ.perimeter());
        System.out.println("Triangle -> Area: " + tri.area() + ", Perimeter: " + tri.perimeter());
    }
}
