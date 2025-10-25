/*28. Write a Java program to create a class called Rectangle with private instance variables
    length and width. Provide public getter and setter methods to access and modify these variables.*/

import java.io.*;

class p28 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Create a Rectangle object
        Rectangle rect = new Rectangle();

        // Input and set length
        System.out.print("Enter length of rectangle: ");
        rect.setLength(Double.parseDouble(br.readLine()));

        // Input and set width
        System.out.print("Enter width of rectangle: ");
        rect.setWidth(Double.parseDouble(br.readLine()));

        // Display rectangle details using getters
        System.out.println("\nRectangle Details:");
        System.out.println("Length: " + rect.getLength());
        System.out.println("Width: " + rect.getWidth());
        System.out.println("Area: " + rect.getLength() * rect.getWidth());
        System.out.println("Perimeter: " + 2 * (rect.getLength() + rect.getWidth()));
    }
}

// Rectangle class demonstrating encapsulation
class Rectangle {
    private double length;
    private double width;

    // Getter for length
    public double getLength() {
        return length;
    }

    // Setter for length
    public void setLength(double l) {
        length = l;
    }

    // Getter for width
    public double getWidth() {
        return width;
    }

    // Setter for width
    public void setWidth(double w) {
        width = w;
    }
}
