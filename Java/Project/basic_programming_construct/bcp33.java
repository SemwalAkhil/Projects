import java.util.*;

// 33. Java Program to find area of Prism
public class bcp33 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Total base area of prism : ");
        double area = scanner.nextDouble();
        System.out.print("Total base perimeter of prism : ");
        double perimeter = scanner.nextDouble();
        System.out.print("Height of then prism : ");
        double height = scanner.nextDouble();
        System.out.println("Total Surface Area of prism with area %.2f perimeter %.2f height %.2f : %.2f"
                .formatted(area, perimeter, height, 2 * area + perimeter * height));
        scanner.close();
    }
}
