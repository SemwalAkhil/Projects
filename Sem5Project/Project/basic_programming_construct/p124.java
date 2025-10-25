import java.util.Scanner;

public class SumOfDigits {
    static int sumDigits(int num) {
        int sum = 0;
        int n = Math.abs(num); // handle negative numbers
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int number = sc.nextInt();

        int sum = sumDigits(number);
        System.out.println("Sum of digits: " + sum);
        sc.close();
    }
}
output:-
        Enter an integer: 12345
        Sum of digits: 15
        