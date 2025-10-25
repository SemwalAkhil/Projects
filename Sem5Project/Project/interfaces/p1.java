// 1. Write a Java program to create an interface Shape with the getArea() method. Create three classes Rectangle, Circle, and Triangle that implement the Shape interface. Implement the getArea() method for each of the three classes.

interface Shape {
    double getArea();
}

class Rectangle implements Shape {
    double length, width;
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    public double getArea() {
        return length * width;
    }
}

class Circle implements Shape {
    double radius;
    Circle(double r) {
        radius = r;
    }
    public double getArea() {
        return 3.1416 * radius * radius;
    }
}

class Triangle implements Shape {
    double base, height;
    Triangle(double b, double h) {
        base = b;
        height = h;
    }
    public double getArea() {
        return 0.5 * base * height;
    }
}

public class Main {
    public static void main(String[] args) {
        Shape r = new Rectangle(5, 10);
        Shape c = new Circle(7);
        Shape t = new Triangle(6, 8);

        System.out.println("Rectangle Area: " + r.getArea());
        System.out.println("Circle Area: " + c.getArea());
        System.out.println("Triangle Area: " + t.getArea());
    }
}

/*
Output:
Rectangle Area: 50.0
Circle Area: 153.9384
Triangle Area: 24.0
*/
