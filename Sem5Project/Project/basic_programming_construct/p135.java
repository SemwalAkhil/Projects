import java.util.Scanner;

public class IsInteger {
    static boolean isInteger(double num) {
        return num == (int)num;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter double number: ");
        double n = sc.nextDouble();

        if (isInteger(n))
            System.out.println(n + " is an integer.");
        else
            System.out.println(n + " is not an integer.");
        sc.close();
    }
}
output:-
        Enter double number: 25.0
        25.0 is an integer.
        