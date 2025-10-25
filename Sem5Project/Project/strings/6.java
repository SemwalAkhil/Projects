import java.util.Scanner;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the original string: ");
        String original = sc.nextLine();

        System.out.print("Enter the string to insert: ");
        String toInsert = sc.nextLine();

        System.out.print("Enter the position to insert at (0-based index): ");
        int position = sc.nextInt();

        // Create StringBuffer with original string
        StringBuffer sb = new StringBuffer(original);

        // Insert string at the specified position
        sb.insert(position, toInsert);

        System.out.println("String after insertion: " + sb);

        sc.close();
    }
}
