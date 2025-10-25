import java.util.Scanner;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first string: ");
        String str1 = sc.nextLine().toLowerCase();

        System.out.print("Enter second string: ");
        String str2 = sc.nextLine().toLowerCase();

        if (str1.length() != str2.length()) {
            System.out.println("Not anagrams");
        } else {
            boolean isAnagram = true;

            // convert second string to char array
            char[] arr2 = str2.toCharArray();

            // check each character
            for (int i = 0; i < str1.length(); i++) {
                char ch = str1.charAt(i);
                boolean found = false;

                for (int j = 0; j < arr2.length; j++) {
                    if (ch == arr2[j]) {
                        arr2[j] = 0; // mark this character as used
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    isAnagram = false;
                    break;
                }
            }

            if (isAnagram) {
                System.out.println("Strings are anagrams");
            } else {
                System.out.println("Not anagrams");
            }
        }

        sc.close();
    }
}
