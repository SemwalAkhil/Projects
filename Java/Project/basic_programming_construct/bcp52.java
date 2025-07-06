import java.util.*;

// 52. Write a Java program to take three numbers from the user and print the greatest number
public class bcp52 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number : ");
        int x = scanner.nextInt();
        System.out.print("Enter second number : ");
        int y = scanner.nextInt();
        System.out.print("Enter third number : ");
        int z = scanner.nextInt();
        if (x == y && y == z) {
            System.out.println("%d = %d = %d".formatted(x, y, z));
        } else {
            if (x > y) {
                if (x > z) {
                    System.out.println("%d is greatest".formatted(x));
                } else {
                    System.out.println("%d is greatest".formatted(z));
                }
            } else if (y > x) {
                if (y > z) {
                    System.out.println("%d is greatest".formatted(y));
                } else {
                    System.out.println("%d is greatest".formatted(z));
                }
            } else {
                if (z > x) {
                    System.out.println("%d is greatest".formatted(z));
                } else {
                    System.out.println("%d is greatest".formatted(x));
                }
            }
        }
        scanner.close();
    }
}
