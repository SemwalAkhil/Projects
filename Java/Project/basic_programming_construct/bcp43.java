import java.util.*;

// 43. Java program to sum of N numbers
public class bcp43 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Number of numbers : ");
        int n = scanner.nextInt();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            System.out.print("Enter number %d : ".formatted(i + 1));
            sum += scanner.nextInt();
        }
        System.out.print("Sum of %d numbers : %d".formatted(n, sum));
        scanner.close();
    }
}
