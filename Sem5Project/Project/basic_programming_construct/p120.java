import java.util.Scanner;

public class Average {
    static double computeAverage(double a, double b, double c) {
        return (a + b + c)/3;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter three numbers: ");
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double z = sc.nextDouble();
        System.out.println("Average: " + computeAverage(x, y, z));
        sc.close();
    }
}
output:-
        Enter three numbers: 10 20 30
        Average: 20.0
        