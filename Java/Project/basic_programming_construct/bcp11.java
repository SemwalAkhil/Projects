import java.util.*;

// 11. Write a Java program to compare two numbers
public class bcp11 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number : ");
        int x = scanner.nextInt();
        System.out.print("Enter second number : ");
        int y = scanner.nextInt();
        System.out.print(x + (x > y ? " > " : (x != y ? " < " : " = ")) + y);
        scanner.close();
    }
}
