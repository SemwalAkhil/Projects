import java.util.*;

// 42. Java program to check vowel or consonant
public class bcp42 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter character : ");
        char x = scanner.nextLine().charAt(0);
        char[] vowel = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        boolean consonant = true;
        if ('a' <= x && x <= 'z' || 'A' <= x && x <= 'Z') {
            for (char c : vowel) {
                if (x == c) {
                    System.out.println("%c is vowel".formatted(x));
                    consonant = false;
                    break;
                }
            }
            if (consonant) {
                System.out.println("%c is consonant".formatted(x));
            }
        } else {
            System.out.println("Enter a valid character and try again");
        }
        scanner.close();
    }
}
