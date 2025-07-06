import java.util.*;

// 49. Java Pogram to Calculate Commission Percentage
public class bcp49 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter commission % : ");
        double commission = scanner.nextDouble();
        System.out.print("Enter amount : ");
        double amount = scanner.nextDouble();
        System.out.println("Commission : %.2f".formatted(amount * commission * 0.01));
        scanner.close();
    }
}
