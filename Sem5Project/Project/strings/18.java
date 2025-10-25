class Main {
    public static void main(String[] args) {
        String str1 = "ABCD";
        String str2 = "CDAB";

        // Check if lengths are equal
        if (str1.length() != str2.length()) {
            System.out.println(str2 + " is NOT a rotation of " + str1);
        } else {
            // Concatenate str1 with itself
            String temp = str1 + str1;

            // Check if str2 is substring of concatenated string
            if (temp.contains(str2)) {
                System.out.println(str2 + " is a rotation of " + str1);
            } else {
                System.out.println(str2 + " is NOT a rotation of " + str1);
            }
        }
    }
}