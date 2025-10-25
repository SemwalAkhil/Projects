//49. Java Pogram to Calculate Commission Percentage
import java.util.Scanner;

public class CommissionPercentage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total sales amount: ");
        double totalSales = sc.nextDouble();
        System.out.print("Enter commission received: ");
        double commission = sc.nextDouble();
        if (totalSales == 0)
            System.out.println("\nCommission percentage cannot be calculated (sales is zero).");
        else 
        {
            double commissionPercentage = (commission / totalSales) * 100;
            System.out.println("\nCommission Percentage = " + commissionPercentage + " %");
        }
    }
}