class Main {
    public static void main(String[] args) {
        String str = "I love Java";

        int count = 1; // start with 1 word

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                count++;
            }
        }

        System.out.println("Number of words: " + count);
    }
}
