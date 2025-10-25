import java.util.Scanner;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the original string: ");
        String str = sc.nextLine();

        System.out.print("Enter the character to add: ");
        char ch = sc.next().charAt(0); // read a single character

        // Add character to the end of string
        str = str + ch; // String is immutable, so we create a new string

        System.out.println("String after adding character: " + str);

        sc.close();
    }
}
