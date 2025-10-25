import java.util.Scanner;

public class ReverseDigits {
    static int reverseNumber(int num) {
        int rev = 0;
        while (num != 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int number = sc.nextInt();
        System.out.println("Reversed number: " + reverseNumber(number));
        sc.close();
    }
}
output:-
        Enter an integer: 12345
        Reversed number: 54321
        