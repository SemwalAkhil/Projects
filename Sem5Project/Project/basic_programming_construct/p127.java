import java.util.Scanner;

public class PentagonArea {
    static double areaOfPentagon(double side) {
        double apothem = side / (2 * Math.tan(Math.PI / 5));
        return (5 * side * apothem) / 2;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter side of pentagon: ");
        double side = sc.nextDouble();
        System.out.println("Area of pentagon: " + areaOfPentagon(side));
        sc.close();
    }
}
output:-
        Enter side of pentagon: 6
        Area of pentagon: 61.93718642120281
        