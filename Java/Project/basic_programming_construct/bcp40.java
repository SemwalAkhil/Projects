import java.util.*;

// 40. Java program to find surface area of cube
public class bcp40 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter side of cube : ");
        double s = scanner.nextDouble();
        System.out.println("Total surface area : %.2f".formatted(6 * s * s));
        scanner.close();
    }
}
