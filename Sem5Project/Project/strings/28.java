 class Main {
    public static void main(String[] args) {
        String str = "aabbbccddddee"; 
        int maxLen = 1, curLen = 1;
        char maxChar = str.charAt(0);

        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == str.charAt(i - 1)) {
                curLen++; // increment current repeating sequence length
            } else {
                curLen = 1; // reset length when character changes
            }

            if (curLen > maxLen) {
                maxLen = curLen; // update maximum length
                maxChar = str.charAt(i); // store character of longest sequence
            }
        }

        System.out.println("Longest repeating sequence character: " + maxChar);
        System.out.println("Length of sequence: " + maxLen);
    }
}