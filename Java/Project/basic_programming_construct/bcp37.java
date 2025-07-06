import java.util.*;

// 37. Java Program to find volume of cone
public class bcp37 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter base radius : ");
        double r = scanner.nextDouble();
        System.out.print("Enter height : ");
        double h = scanner.nextDouble();
        System.out
                .println("Volume of cone with radius %.2f height %.2f : %.2f".formatted(r, h,
                        (1.0 / 3) * 3.14 * r * r * h));
        scanner.close();
    }
}
