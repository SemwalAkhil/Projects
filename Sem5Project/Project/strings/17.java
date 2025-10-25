class Main {
    public static void main(String[] args) {
        String str = "madam";

        // Reverse the string using StringBuilder
        String reversed = new StringBuilder(str).reverse().toString();

        // Check if original and reversed are same
        if (str.equals(reversed)) {
            System.out.println(str + " is a palindrome");
        } else {
            System.out.println(str + " is not a palindrome");
        }
    }
}
