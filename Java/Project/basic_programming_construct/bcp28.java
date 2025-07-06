import java.util.*;

// 28. Java Program to find area of rectangle
public class bcp28 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter length : ");
        double length = scanner.nextDouble();
        System.out.print("Enter breadth : ");
        double breadth = scanner.nextDouble();
        System.out.println(
                "Area of rectangle with length %.2f breadth %.2f : %.2f".formatted(length, breadth, length * breadth));
        scanner.close();
    }
}
