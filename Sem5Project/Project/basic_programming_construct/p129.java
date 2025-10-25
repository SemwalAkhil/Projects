import java.util.Scanner;

public class PalindromeNumber {
    static boolean isPalindrome(int num) {
        int rev = 0, original = num;
        while (num != 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev == original;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        if (isPalindrome(n))
            System.out.println(n + " is a palindrome.");
        else
            System.out.println(n + " is not a palindrome.");
        sc.close();
    }
}
output:-
        Enter a number: 121
        121 is a palindrome.
        