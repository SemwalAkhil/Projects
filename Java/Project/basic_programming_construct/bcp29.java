import java.util.*;

// 29. Java Program to find area of triangle
public class bcp29 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter perpendicular height : ");
        double height = scanner.nextDouble();
        System.out.print("Enter base length : ");
        double base = scanner.nextDouble();
        System.out.println(
                "Area of triangle with height %.2f base %.2f : %.2f".formatted(height, base, 0.5 * base * height));
        scanner.close();
    }
}
