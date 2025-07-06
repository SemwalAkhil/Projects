import java.util.*;

// 47. Java Program to calculate compound interest
public class bcp47 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter principal : ");
        double principal = scanner.nextDouble();
        System.out.print("Enter rate of interest in % : ");
        double rate = scanner.nextDouble();
        System.out.print("Enter time period in years : ");
        double time = scanner.nextDouble();
        System.out.print("Number of time compounded in year : ");
        int number = scanner.nextInt();
        double amount = principal * Math.pow((1 + ((rate / 100) / number)), number * time);
        System.out.println("Compound Interest = %.2f - %.2f = %.2f".formatted(amount, principal, amount - principal));
        scanner.close();
    }
}
