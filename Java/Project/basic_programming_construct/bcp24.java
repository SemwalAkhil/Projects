import java.util.*;

// 24. Write a Java program to check if a positive number is a palindrome or not
public class bcp24 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive int : ");
        int x = scanner.nextInt();
        if (x < 0) {
            System.out.println("Pallindrome check failed enter a positive number");
        } else {
            int temp = x;
            int y = 0;
            while (temp != 0) {
                y = y * 10 + temp % 10;
                temp /= 10;
            }
            if (x == y) {
                System.out.println("Pallindrome");
            } else {
                System.out.println("Not Pallindrome");
            }
        }
        scanner.close();
    }
}
