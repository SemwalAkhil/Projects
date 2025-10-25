/*24. Create a class showing the area of circle and rectangle by method overloading.*/

import java.io.*;

class p24 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        AreaCalculator ac = new AreaCalculator(); // Create object for area calculations

        // Rectangle input
        System.out.print("Enter length of rectangle: ");
        double length = Double.parseDouble(br.readLine());

        System.out.print("Enter width of rectangle: ");
        double width = Double.parseDouble(br.readLine());

        // Circle input
        System.out.print("Enter radius of circle: ");
        double radius = Double.parseDouble(br.readLine());

        // Display areas
        System.out.println("\nArea of Rectangle: " + ac.area(length, width));
        System.out.println("Area of Circle: " + ac.area(radius));
    }
}

// Class demonstrating method overloading
class AreaCalculator {

    // Method to calculate area of rectangle
    double area(double length, double width) {
        return length * width;
    }

    // Method to calculate area of circle
    double area(double radius) {
        return Math.PI * radius * radius;
    }
}
