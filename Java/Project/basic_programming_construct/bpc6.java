import java.util.*;

// 6. Write a Java program to swap two variables
public class bpc6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter x : ");
        int x = scanner.nextInt();
        System.out.print("Enter y : ");
        int y = scanner.nextInt();
        int z = x;
        x = y;
        y = z;
        System.out.println("New values of x : " + x + " and y : " + y);
        scanner.close();
    }
}
