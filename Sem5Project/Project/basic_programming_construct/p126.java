import java.util.Scanner;

public class TriangleArea {
    static double areaOfTriangle(double base, double height) {
        return 0.5 * base * height;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter base of triangle: ");
        double base = sc.nextDouble();
        System.out.print("Enter height of triangle: ");
        double height = sc.nextDouble();
        System.out.println("Area of triangle: " + areaOfTriangle(base, height));
        sc.close();
    }
}
output:-
        Enter base of triangle: 10
        Enter height of triangle: 5
        Area of triangle: 25.0
        