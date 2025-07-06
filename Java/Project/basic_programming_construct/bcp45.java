import java.util.*;

// 45. Java Program to calculate electricity bill
public class bcp45 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter electricity consumption in kW : ");
        double x = scanner.nextDouble();
        double total = 40; // Fixed charge
        if (x < 0) {
            System.out.print("Consumption must be greater than 0");
        } else {
            total += x * 0.06;
            if (x >= 0 && x <= 150) {
                total += x * 2.75; // rate upto 150 kW
            } else if (x >= 151 && x <= 400) {
                total += 150 * 2.75;
                total += (x - 150) * 4.9; // rate upto 400
            } else {
                total += 150 * 2.75;
                total += 250 * 2.75;
                total += (x - 400) * 5.5; // rate above 400
            }
        }
        System.out.println("Your bill : %.2f".formatted(total));
        scanner.close();
    }
}
