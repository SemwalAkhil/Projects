import java.util.*;

// 13. Write a Java program to print the ascii value of a given character
public class bcp13 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter character : ");
        char x = scanner.next().charAt(0);
        System.out.println("Ascii of %c : %d".formatted(x, (int) x));
        scanner.close();
    }
}
