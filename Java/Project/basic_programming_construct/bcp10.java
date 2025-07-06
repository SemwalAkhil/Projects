import java.util.*;

// 10. Write a Java program and compute the sum of the digits of an integer
public class bcp10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer : ");
        int x = scanner.nextInt();
        int sum = 0;
        while (x != 0) {
            sum += x % 10;
            x /= 10;
        }
        System.out.println("Sum is : " + sum);
        scanner.close();
    }
}
