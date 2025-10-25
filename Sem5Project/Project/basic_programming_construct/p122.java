import java.util.Scanner;

public class WordCount {
    static int countWords(String str) {
        String trimmed = str.trim();
        if (trimmed.isEmpty()) return 0;
        int count = 1;
        for (int i = 0; i < trimmed.length() - 1; i++) {
            if (trimmed.charAt(i) == ' ' && trimmed.charAt(i+1) != ' ') {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a sentence:");
        String sentence = sc.nextLine();

        int wordCount = countWords(sentence);
        System.out.println("Number of words: " + wordCount);
        sc.close();
    }
}
output:-
        Enter a sentence:
        This is a sample sentence
        Number of words: 5
        