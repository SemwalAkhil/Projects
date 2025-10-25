import java.util.Scanner;

public class SmallestOfThree {
    static int findSmallest(int a, int b, int c) {
        int smallest = a;
        if (b < smallest) smallest = b;
        if (c < smallest) smallest = c;
        return smallest;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter three numbers: ");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int num3 = sc.nextInt();

        int smallest = findSmallest(num1, num2, num3);
        System.out.println("Smallest number is: " + smallest);
        sc.close();
    }
}
output:-
        Enter three numbers: 10 5 20
        Smallest number is: 5
        