import java.util.Scanner;

public class GCDLCM {
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        int x = sc.nextInt();
        int y = sc.nextInt();

        System.out.println("GCD: " + gcd(x, y));
        System.out.println("LCM: " + lcm(x, y));
        sc.close();
    }
}
output:-
        Enter two numbers: 24 36
        GCD: 12
        LCM: 72
        