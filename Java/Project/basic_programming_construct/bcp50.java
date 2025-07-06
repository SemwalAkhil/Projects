import java.util.*;

// 50. Java Pogram To Find Distance Between Two Points
public class bcp50 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter x-coordinate of point 1 : ");
        double x1 = scanner.nextDouble();
        System.out.print("Enter y-coordinate of point 1 : ");
        double y1 = scanner.nextDouble();
        System.out.print("Enter x-coordinate of point 2 : ");
        double x2 = scanner.nextDouble();
        System.out.print("Enter y-coordinate of point 2 : ");
        double y2 = scanner.nextDouble();
        double distance = Math.pow(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2), 0.5);
        System.out.println("Distance between (%.2f,%.2f) and (%.2f,%.2f) = %.2f".formatted(x1, y1, x2, y2, distance));
        scanner.close();
    }
}
