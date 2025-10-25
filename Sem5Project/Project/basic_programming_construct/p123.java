import java.util.Scanner;

public class VowelCount {
    static int countVowels(String str) {
        int count = 0;
        String lower = str.toLowerCase();
        for (int i = 0; i < lower.length(); i++) {
            char ch = lower.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String input = sc.nextLine();

        int vowels = countVowels(input);
        System.out.println("Number of vowels: " + vowels);
        sc.close();
    }
}
output:-
        Enter a string:
        Hello World
        Number of vowels: 3
        