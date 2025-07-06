import java.util.*;

// 36. Java Program to find volume of cuboid
public class bcp36 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter length : ");
        double l = scanner.nextDouble();
        System.out.print("Enter breadth : ");
        double b = scanner.nextDouble();
        System.out.print("Enter width : ");
        double h = scanner.nextDouble();
        System.out.println(
                "Volume of cuboid with length %.2f breadth %.2f height %.2f : %.2f".formatted(l, b, h, l * b * h));
        scanner.close();
    }
}
