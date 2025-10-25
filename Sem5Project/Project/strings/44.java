import java.util.Scanner;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read first string
        System.out.print("Enter the first string: ");
        String str1 = sc.nextLine();

        // Read second string
        System.out.print("Enter the second string: ");
        String str2 = sc.nextLine();

        // Check if first string contains the second
        if (str1.contains(str2)) {
            System.out.println("Yes! The first string contains the second string.");
        } else {
            System.out.println("No! The first string does not contain the second string.");
        }

        sc.close();
    }
}