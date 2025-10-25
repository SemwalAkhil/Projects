import java.util.Scanner;

public class RoundUpDivision {
    static int ceilDivide(int num, int den) {
        return (num + den - 1) / den;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter numerator: ");
        int a = sc.nextInt();
        System.out.print("Enter denominator: ");
        int b = sc.nextInt();

        System.out.println("Rounded up division result: " + ceilDivide(a, b));
        sc.close();
    }
}
output:-
        Enter numerator: 10
        Enter denominator: 3
        Rounded up division result: 4
        