import java.util.Scanner;

public class FactorialRecursion {
    static int factorial(int n) {
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number: ");
        int num = sc.nextInt();

        System.out.println("Factorial of " + num + " is " + factorial(num));
        sc.close();
    }
}
output:-
        Enter number: 5
        Factorial of 5 is 120
        