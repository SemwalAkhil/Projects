import java.util.Arrays;
import java.util.Scanner;
 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first string: ");
        String str1 = sc.nextLine();

        System.out.print("Enter second string: ");
        String str2 = sc.nextLine();

        // Remove spaces and convert to lowercase for uniformity
        str1 = str1.replaceAll("\\s", "").toLowerCase();
        str2 = str2.replaceAll("\\s", "").toLowerCase();

        // Convert strings to char arrays
        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();

        // Sort the char arrays
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        // Compare sorted arrays
        if (Arrays.equals(arr1, arr2)) {
            System.out.println("Yes! Both strings are made of the same characters.");
        } else {
            System.out.println("No! Strings are not made of the same characters.");
        }

        sc.close();
    }
}
