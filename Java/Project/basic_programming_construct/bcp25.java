import java.util.*;

// 25. Write a Java program to add two numbers without using any arithmetic operators
public class bcp25 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number : ");
        int x = scanner.nextInt();
        System.out.print("Enter second number : ");
        int y = scanner.nextInt();
        // METHOD 1
        int sum = Math.addExact(x, y);
        System.out.println("%d + %d = %d".formatted(x, y, sum));
        // METHOD 2
        sum = x;
        int b = y;
        // assume a case 5 0101 6 0110
        while (b != 0) {
            int carry = sum & b;
            sum = sum ^ b;
            b = carry << 1;
            /*
             * ============================
             * || 0 & 0 = 0 || 0 ^ 0 = 0 ||
             * || 0 & 1 = 0 || 0 ^ 1 = 1 ||
             * || 1 & 1 = 1 || 1 ^ 1 = 0 ||
             * ============================
             * 0101 & 0110 = 0100 (carry)
             * 0101 ^ 0110 = 0011 (sum)
             * 0100 << 1 = 1000 (shifting carry to add it to next digit)
             * 0011 & 1000 = 0000
             * 0011 ^ 1000 = 1011
             */
        }
        System.out.println("%d + %d = %d".formatted(x, y, sum));
        // METHOD 3
        sum = x;
        if (y > 0) {
            for (int i = 0; i < y; i++, sum++)
                ;
        } else {
            for (int i = 0; i > y; i--, sum--)
                ;
        }

        System.out.println("%d + %d = %d".formatted(x, y, sum));
        scanner.close();
    }
}
/*
 * 
 * 
 * => a & b = carry bit
 * => a ^ b = sum bit
 */
