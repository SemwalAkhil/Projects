import java.util.*;

// 30. Java Program to find area of equilateral triangle
public class bcp30 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter side length : ");
        double length = scanner.nextDouble();
        double semi = (3 * length) / 2;
        double area = Math.pow(semi * (Math.pow((semi - length), 3)), 0.5);
        System.out.println("Area of equilateral triangle with side %.2f : %.2f"
                .formatted(length, area));
        scanner.close();
    }
}
