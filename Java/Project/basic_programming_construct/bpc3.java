import java.util.Scanner;

// 3. Write a Java program that takes two numbers and display the product of two numbers
public class bpc3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number : ");
        int x = scanner.nextInt();
        System.out.print("Enter second number : ");
        int y = scanner.nextInt();
        System.out.println("Product of " + x + " and " + y + " is " + (x * y));
        scanner.close();
    }
}
