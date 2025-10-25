import java.util.Scanner;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        System.out.print("Enter character to remove: ");
        char removeChar = sc.next().charAt(0); // read single character

        String result = ""; // empty string to store result

        // loop through each character of the input string
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch != removeChar) { // add only if it's not the character to remove
                result += ch;
            }
        }

        System.out.println("String after removal: " + result);
        sc.close();
    }
}