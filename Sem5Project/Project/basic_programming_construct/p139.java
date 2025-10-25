import java.util.Scanner;

public class RoundedFloat {
    static float roundFloat(float num) {
        return Math.round(num * 100.0f) / 100.0f; // rounds to 2 decimal places
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a float number: ");
        float n = sc.nextFloat();

        System.out.println("Rounded value: " + roundFloat(n));
        sc.close();
    }
}
output:-
        Enter a float number: 3.14159
        Rounded value: 3.14
        