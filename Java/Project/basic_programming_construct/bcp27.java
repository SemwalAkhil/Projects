import java.util.*;

// 27. Java program to find area of circle
public class bcp27 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the radius : ");
        double radius = scanner.nextDouble();
        System.out.println("Area of circle with radius %.2f : %.2f".formatted(radius, 3.14 * radius * radius));
        scanner.close();
    }
}
