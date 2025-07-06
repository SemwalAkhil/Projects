import java.util.*;

// 18. Write a Java program to convert a string to an integer
public class bcp18 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string containing integer : ");
        char[] str = scanner.next().toCharArray();
        int x = 0;
        boolean neg = false;
        boolean valid = true;
        for (int i = 0; i < str.length; i++) {
            if (i == 0 && str[i] == '-') {
                neg = true;
                continue;
            }
            if (str[i] < 48 || str[i] > 57) {
                System.out.println("Invalid String. String must contain only integers.");
                valid = false;
                break;
            } else {
                x = x * 10 + str[i] - 48;
            }
        }
        if (valid) {
            if (neg) {
                System.out.println("Converted int : %d".formatted(-1 * x));
            }
        }

        scanner.close();
    }
}
