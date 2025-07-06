import java.util.*;

// 14. Write a Java program that accepts an integer (n) and computes the value of n+nn+nnn
public class bcp14 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter integer : ");
        int x = scanner.nextInt();
        System.out.println("%d+(%d)(%d)+(%d)(%d)(%d) = %d".formatted(x, x, x, x, x, x, x + x * x + x * x * x));
        scanner.close();
    }
}
