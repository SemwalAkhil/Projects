import java.util.Scanner;

public class PrimeCheck {
    static boolean isPrime(int num) {
        if(num <= 1) return false;
        for(int i=2; i <= num/2; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        if(isPrime(n))
            System.out.println(n + " is a prime number.");
        else
            System.out.println(n + " is not a prime number.");
        sc.close();
    }
}
output:-
        Enter a number: 17
        17 is a prime number.
        