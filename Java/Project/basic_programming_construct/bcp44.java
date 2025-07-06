import java.util.*;

// 44. Java program to find factorial of any number
public class bcp44 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number : ");
        int n = scanner.nextInt();
        if (n < 0) {
            System.out.println("Factorial does not exist for negative number : %d".formatted(n));
        } else {
            int fact = 1;
            for (int i = n; i > 0; i--) {
                fact *= i;
            }
            System.out.println("Factorial of %d : %d".formatted(n, fact));
        }
        scanner.close();
    }
}
