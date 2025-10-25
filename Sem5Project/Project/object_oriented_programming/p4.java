// Main class to demonstrate accessing, modifying, and calculating Circle properties
class p4 {
    public static void main(String st[]) {
        // Create Circle object with initial radius 5.7
        Circle c1 = new Circle(5.7);
        // Display initial radius
        System.out.printf("Radius of Circle : %.4f\n", c1.getradius());
        // Modify radius to 7.5
        c1.modify(7.5);
        // Display updated radius
        System.out.printf("Updated radius of Circle : %.4f\n", c1.getradius());
        // Display area of the circle with 4 decimal places
        System.out.printf("Area of Circle : %.4f\n", c1.area());
        // Display circumference of the circle with 4 decimal places
        System.out.printf("Circumference of Circle : %.4f\n", c1.circumference());
    }
}
// Circle class with a radius attribute
class Circle {
    double radius;
    // Constructor to initialize radius
    Circle(double r) {
        radius = r;
    }
    // Method to get current radius
    double getradius() {
        return radius;
    }
    // Method to modify the radius
    void modify(double r) {
        radius = r;
    }
    // Method to calculate area of the circle
    double area() {
        return Math.PI * radius * radius;
    }
    // Method to calculate circumference of the circle
    double circumference() {
        return 2 * Math.PI * radius;
    }
}
