import java.util.Scanner;

public class LargestSmallest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int largest = Integer.MIN_VALUE;
        int smallest = Integer.MAX_VALUE;

        char choice;

        do {
            System.out.print("Enter a number: ");
            int num = sc.nextInt();

            if(num > largest) largest = num;
            if(num < smallest) smallest = num;

            System.out.print("Do you want to enter another number? (y/n): ");
            choice = sc.next().charAt(0);

        } while(choice == 'y' || choice == 'Y');

        System.out.println("Largest number entered: " + largest);
        System.out.println("Smallest number entered: " + smallest);
        sc.close();
    }
}
output:-
        Enter a number: 10
        Do you want to enter another number? (y/n): y
        Enter a number: 5
        Do you want to enter another number? (y/n): y
        Enter a number: 20
        Do you want to enter another number? (y/n): n
        Largest number entered: 20
        Smallest number entered: 5
        