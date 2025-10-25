import java.util.Scanner;

public class CountPosNegZero {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int positive = 0, negative = 0, zero = 0;
        char choice;

        do {
            System.out.print("Enter a number: ");
            int num = sc.nextInt();

            if(num > 0) positive++;
            else if(num < 0) negative++;
            else zero++;

            System.out.print("Do you want to enter another number? (y/n): ");
            choice = sc.next().charAt(0);

        } while(choice == 'y' || choice == 'Y');

        System.out.println("Positive numbers count: " + positive);
        System.out.println("Negative numbers count: " + negative);
        System.out.println("Zero count: " + zero);
        sc.close();
    }
}
output:-
        Enter a number: 5
        Do you want to enter another number? (y/n): y
        Enter a number: -3
        Do you want to enter another number? (y/n): y
        Enter a number: 0
        Do you want to enter another number? (y/n): y
        Enter a number: 7
        Do you want to enter another number? (y/n): n
        Positive numbers count: 2
        Negative numbers count: 1
        Zero count: 1
        