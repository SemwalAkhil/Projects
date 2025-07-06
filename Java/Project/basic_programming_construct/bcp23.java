import java.util.*;

// 23. Write a Java program to compute the square root of an given integer
public class bcp23 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter integer : ");
        int x = scanner.nextInt();
        if (x < 0) {
            System.out.println("Real root does not exist for negative numbers");
        } else {
            double y = Math.sqrt(x);
            System.out.println("y : %.2f".formatted(y));
        }
        scanner.close();
    }
}
