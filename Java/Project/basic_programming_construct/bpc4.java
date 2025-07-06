import java.util.*;

// 4. Write a Java program to print the sum, multiply, subtract, divide and remainder of two numbers
public class bpc4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number : ");
        int x = scanner.nextInt();
        System.out.print("Enter next number : ");
        int y = scanner.nextInt();
        System.out.println(x + " + " + y + " is : " + (x + y));
        System.out.println(x + " * " + y + " is : " + (x * y));
        System.out.println(x + " - " + y + " is : " + (x - y));
        System.out.println(x + " / " + y + " is : " + (x / y));
        System.out.println(x + " % " + y + " is : " + (x % y));
        scanner.close();
    }
}
