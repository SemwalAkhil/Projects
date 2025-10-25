import java.util.Scanner;

public class SeriesSum {
    static double sumSeries(int n) {
        double sum = 0.0;
        for(int i=1; i<=n; i++) {
            sum += 1.0/i;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        System.out.println("Sum of series: " + sumSeries(n));
        sc.close();
    }
}
output:-
        Enter n: 5
        Sum of series: 2.283333333333333
        