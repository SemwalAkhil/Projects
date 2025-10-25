import java.util.Scanner;

public class RoundFloat {
    static double roundToDecimals(double num, int decimals) {
        double multiplier = Math.pow(10, decimals);
        return Math.round(num * multiplier) / multiplier;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter float number: ");
        double number = sc.nextDouble();
        System.out.print("Decimals to round: ");
        int dec = sc.nextInt();

        System.out.println("Rounded value: " + roundToDecimals(number, dec));
        sc.close();
    }
}
output:-
        Enter float number: 3.14159
        Decimals to round: 2
        Rounded value
        