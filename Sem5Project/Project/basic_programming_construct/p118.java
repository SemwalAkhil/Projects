import java.util.Scanner;

public class FibonacciSeries {
    static void printFibonacci(int n) {
        int a=0, b=1, c;
        System.out.print(a + " " + b + " ");
        for(int i=2; i<n; i++) {
            c = a + b;
            System.out.print(c + " ");
            a = b;
            b = c;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of terms: ");
        int n = sc.nextInt();
        printFibonacci(n);
        sc.close();
    }
}
output:-
        Enter number of terms: 10
        0 1 1 2 3 5 8 13 21 34 
        