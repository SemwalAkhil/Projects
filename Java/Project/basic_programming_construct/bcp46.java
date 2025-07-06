import java.util.*;

// 46. Java Program To Calculate CGPA Percentage
public class bcp46 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter CGPA (0-10): ");
        double cgpa = scanner.nextDouble();
        if (cgpa >= 0 && cgpa <= 10) {
            System.out.println("Percentage : %.2f %%".formatted(cgpa * 10));
        } else {
            System.out.println("Enter valid CGPA");
        }
        scanner.close();
    }
}
