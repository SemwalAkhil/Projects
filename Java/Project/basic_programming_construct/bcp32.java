import java.util.*;

// 32. Java Program to find area of parallelogram
public class bcp32 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter base of parallelogram : ");
        double base = scanner.nextDouble();
        System.out.print("Enter height of parallelogram : ");
        double height = scanner.nextDouble();
        System.out.println(
                "Area of parallelogram with base %.2f height %.2f : %.2f".formatted(base, height, base * height));
        scanner.close();
    }
}
