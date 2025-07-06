import java.util.*;

// 38. Java program to find surface area of cuboid
public class bcp38 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter length : ");
        double l = scanner.nextDouble();
        System.out.print("Enter breadth : ");
        double b = scanner.nextDouble();
        System.out.print("Enter width : ");
        double h = scanner.nextDouble();
        System.out.println("Total surface area of cuboid : %.2f".formatted(2 * (l * b + b * h + h * l)));
        scanner.close();
    }
}
