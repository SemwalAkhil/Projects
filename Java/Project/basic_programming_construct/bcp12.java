import java.util.*;

// 12. Write a Java program to count the letters, spaces, numbers and other characters of an input string
public class bcp12 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string : ");
        char[] mystr = scanner.nextLine().toCharArray();
        int letters = 0, spaces = 0, numbers = 0, others = 0;
        for (int i = 0; i < mystr.length; i++) {
            // System.out.println((int) mystr[i]);
            if (mystr[i] >= 65 && mystr[i] <= 90 || mystr[i] >= 97 && mystr[i] <= 122) {
                letters++;
            } else if (mystr[i] >= 48 && mystr[i] <= 57) {
                numbers++;
            } else if (mystr[i] == 32) {
                spaces++;
            } else {
                others++;
            }
        }
        System.out
                .println("Letter count : %d\nSpace count : %d\nNumbers count : %d\nOthers count : %d".formatted(letters,
                        spaces, numbers, others));
        scanner.close();
    }
}
