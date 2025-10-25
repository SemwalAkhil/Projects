/*30. Write a Java program to create a class called Circle with a private instance variable radius.
    Provide public getter and setter methods to access and modify the radius variable.
    Also, provide two methods called calculateArea() and calculatePerimeter() that return
    the calculated area and perimeter based on the current radius value.*/

import java.io.*;

class p30 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Create Circle object
        Circle c = new Circle();

        // Input radius
        System.out.print("Enter radius of the circle: ");
        c.setRadius(Double.parseDouble(br.readLine()));

        // Display circle details and calculations
        System.out.println("\nCircle Details:");
        System.out.println("Radius: " + c.getRadius());
        System.out.println("Area: " + c.calculateArea());
        System.out.println("Perimeter: " + c.calculatePerimeter());
    }
}

// Circle class demonstrating encapsulation and calculation methods
class Circle {
    private double radius;

    // Getter for radius
    public double getRadius() {
        return radius;
    }

    // Setter for radius
    public void setRadius(double r) {
        radius = r;
    }

    // Method to calculate area
    public double calculateArea() {
        return 3.14159 * radius * radius; // πr^2
    }

    // Method to calculate perimeter (circumference)
    public double calculatePerimeter() {
        return 2 * 3.14159 * radius; // 2πr
    }
}
