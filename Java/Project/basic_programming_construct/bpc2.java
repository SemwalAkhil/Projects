import java.util.Scanner;

// 2. Write a Java program to print the sum of two numbers
public class bpc2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number : ");
        int num1 = scanner.nextInt();
        System.out.print("Enter second number : ");
        int num2 = scanner.nextInt();
        System.out.print("Sum of " + num1 + " and " + num2 + " is : " + (num1 + num2));
        scanner.close();
    }
}
