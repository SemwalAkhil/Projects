import java.util.*;

// 51. Java Program To Calculate Power Of Number
public class bcp51 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number : ");
        double number = scanner.nextDouble();
        System.out.print("Enter power : ");
        int power = scanner.nextInt();
        double result = 1;
        if (power == 0) {
            result = 1;
        } else if (power == 1) {
            result = number;
        } else if (power > 1) {
            if (number % 1 == 0) {
                result = (int) number << power;
            } else {
                for (int i = 0; i < power; i++) {
                    result *= number;
                }
            }
        } else {
            if (number % 1 == 0) {
                result = 1.0 / ((int) number << (-1 * power));
            } else {
                for (int i = 0; i > power; i--) {
                    result /= number;
                }
            }
        }
        System.out.println("%f ^ %d : %f".formatted(number, power, result));
        scanner.close();
    }
}
