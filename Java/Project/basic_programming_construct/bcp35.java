import java.util.*;

// 35. Java Program to find volume of cylinder
public class bcp35 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter radius of cylinder top : ");
        double r = scanner.nextDouble();
        System.out.print("Enter height of cylinder : ");
        double h = scanner.nextDouble();
        System.out.println(
                "Volume of cylinder with radius %.2f height %.2f : %.2f".formatted(r, h, 3.14 * r * r * h));
        scanner.close();
    }
}
