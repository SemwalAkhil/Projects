import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first string: ");
        String str1 = sc.nextLine();

        System.out.print("Enter second string to append: ");
        String str2 = sc.nextLine();

        // Create StringBuffer object with first string
        StringBuffer sb = new StringBuffer(str1);

        // Append second string
        sb.append(str2);

        System.out.println("After appending: " + sb);

        sc.close();
    }
}
