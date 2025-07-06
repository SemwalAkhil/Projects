import java.util.*;

// 34. Java Program to find volume of sphere
public class bcp34 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter radius : ");
        double r = scanner.nextDouble();
        System.out.println("Volume of sphere with radius %.2f : %.2f".formatted(r, (4.0 / 3) * (3.14) * r * r * r));
        scanner.close();
    }
}
