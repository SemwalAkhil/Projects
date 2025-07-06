import java.util.*;

// 26. Write a Java program to add all the digits of a given positive integer
public class bcp26 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positve integer : ");
        int x = scanner.nextInt();
        if (x < 0) {
            System.out.println("Only positive integer is allowed");
        } else {
            int temp = x, sum = 0;
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            System.out.println("Sum of digits of %d : %d".formatted(x, sum));
        }
        scanner.close();
    }
}
