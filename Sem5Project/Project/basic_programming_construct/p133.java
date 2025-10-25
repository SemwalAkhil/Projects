import java.util.Scanner;

public class ReverseInteger {
    static int reverse(int num) {
        int rev = 0;
        while (num != 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter integer: ");
        int n = sc.nextInt();

        System.out.println("Reversed number: " + reverse(n));
        sc.close();
    }
}
output:-
        Enter integer: 12345
        Reversed number: 54321
        