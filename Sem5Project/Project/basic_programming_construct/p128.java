import java.util.Scanner;

public class IsEven {
    static boolean checkEven(int num) {
        return num % 2 == 0;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        if (checkEven(n))
            System.out.println(n + " is even.");
        else
            System.out.println(n + " is odd.");
        sc.close();
    }
}
output:-
        Enter a number: 8
        8 is even.
        