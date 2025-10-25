/*3. Write a Java program to create a class called "Rectangle" with width and height attributes. Calculate the area and perimeter of the rectangle.*/
class p3 {
    public static void main(String st[]) {
        Rectangle r1 = new Rectangle(5.6, 8.2);
        // Print area with 4 decimal places
        System.out.printf("Area of Rectangle : %.4f\n", r1.area());
        // Print perimeter with 4 decimal places
        System.out.printf("Perimeter of Rectangle : %.4f\n", r1.perimeter());
    }
}
// Rectangle class with width and height attributes
class Rectangle {
    double width;
    double height;
    // Constructor to initialize width and height
    Rectangle(double wd, double hg) {
        width = wd;
        height = hg;
    }
    // Method to calculate area
    double area() {
        return width * height;
    }
    // Method to calculate perimeter
    double perimeter() {
        return 2 * (width + height);
    }
}
