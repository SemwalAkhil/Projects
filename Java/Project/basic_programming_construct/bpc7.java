import java.util.*;

// 7. Write a Java program to convert a decimal number to binary numbers
public class bpc7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number : ");
        int x = scanner.nextInt();
        char[] y = new char[16];
        int count = 0;
        char temp;
        while (x != 0) {
            y[count++] = (x % 2) == 1 ? '1' : '0';
            x = x / 2;
        }
        for (int i = 0; i < 8; i++) {
            temp = y[i];
            y[i] = y[16 - i - 1];
            y[16 - i - 1] = temp;
        }
        System.out.println(y);
        scanner.close();
    }
}
