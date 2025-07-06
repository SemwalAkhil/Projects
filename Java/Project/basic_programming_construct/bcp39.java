import java.util.*;

// 39. Java program to find surface area of cylinder
public class bcp39 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter radius : ");
        double r = scanner.nextDouble();
        System.out.print("Enter height : ");
        double h = scanner.nextDouble();
        System.out.println("Total surface area : %.2f".formatted(2 * 3.14 * r * r + 2 * 3.14 * r * h));
        scanner.close();
    }
}
