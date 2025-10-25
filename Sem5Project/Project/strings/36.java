 class Main {
    public static void main(String[] args) {
        String str = "my madam level is __ ";
        String[] words = str.split(" ");

        String smallest = "";
        String biggest = "";

        for (String word : words) {
            if (isPalindrome(word)) {
                if (smallest.equals("") || word.length() < smallest.length()) {
                    smallest = word;
                }
                if (biggest.equals("") || word.length() > biggest.length()) {
                    biggest = word;
                }
            }
        }

        System.out.println("Smallest palindrome word: " + smallest);
        System.out.println("Biggest palindrome word: " + biggest);
    }

    // Function to check if a word is palindrome
    public static boolean isPalindrome(String word) {
        int i = 0, j = word.length() - 1;
        while (i < j) {
            if (word.charAt(i) != word.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}

