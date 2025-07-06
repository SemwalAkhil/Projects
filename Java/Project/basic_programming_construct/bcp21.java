import java.util.*;

// 21. Write a Java program to swap the first and last elements of an array and create a new array
public class bcp21 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter length of integer array : ");
        int len = scanner.nextInt();
        int[] x = new int[len];
        for (int i = 0; i < len; i++) {
            System.out.print("Enter element %d : ".formatted(i + 1));
            x[i] = scanner.nextInt();
        }
        System.out.print("User array : [");
        for (int i : x) {
            System.out.print(i + " ");
        }
        System.out.println("]");
        int temp = x[0];
        x[0] = x[x.length - 1];
        x[x.length - 1] = temp;
        System.out.print("User array : [");
        for (int i : x) {
            System.out.print(i + " ");
        }
        System.out.println("]");
        scanner.close();
    }
}
