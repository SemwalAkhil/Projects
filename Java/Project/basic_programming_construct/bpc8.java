import java.util.*;

// 8. Write a Java program to convert a binary number to decimal number
public class bpc8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter 8 bit binary string : ");
        char[] x = scanner.next().toCharArray();
        int y = 0;
        int coeff = 128;
        for (int i = 0; i < x.length; i++) {
            if (x[i] == '1') {
                y += coeff;
            }
            coeff /= 2;
        }
        System.out.println(y);
        scanner.close();
    }
}
