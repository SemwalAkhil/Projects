import java.util.Scanner;

// 31. Java Program to find area of rhombus
public class bcp31 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter diagonal 1 of rhombus : ");
        double diagonal1 = scanner.nextDouble();
        System.out.print("Enter diagonal 2 of rhombus : ");
        double diagonal2 = scanner.nextDouble();
        System.out.println("Area of rhombus with diagonals %.2f & %.2f : %.2f".formatted(diagonal1, diagonal2,
                diagonal1 * diagonal2 * 0.5));
        scanner.close();
    }
}
