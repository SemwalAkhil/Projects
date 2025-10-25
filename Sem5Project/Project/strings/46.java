import java.util.Scanner;
 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        // Split the string into words
        String[] words = str.split(" ");
        String reversed = "";

        // Loop from last word to first
        for (int i = words.length - 1; i >= 0; i--) {
            reversed += words[i] + " ";
        }

        System.out.println("Reversed string word by word: " + reversed.trim());
        sc.close();
    }
}

