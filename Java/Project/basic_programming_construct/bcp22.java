import java.util.*;

// 22. Write a Java program to count the number of even and odd elements in a given array
public class bcp22 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter length of integer array : ");
        int len = scanner.nextInt();
        int[] x = new int[len];
        int even = 0, odd = 0;
        for (int i = 0; i < x.length; i++) {
            System.out.print("Enter element %d : ".formatted(i + 1));
            x[i] = scanner.nextInt();
        }
        for (int i = 0; i < x.length; i++) {
            if (x[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        System.out.println("Odd : %d Even : %d".formatted(odd, even));
        scanner.close();
    }
}
