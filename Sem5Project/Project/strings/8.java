import java.util.Scanner;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the original string: ");
        String str = sc.nextLine();

        System.out.print("Enter the character to add: ");
        char ch = sc.next().charAt(0);

        // Create StringBuffer with original string
        StringBuffer sb = new StringBuffer(str);

        // Add character using append()
        sb.append(ch);

        System.out.println("String after adding character: " + sb);

        sc.close();
    }
}
