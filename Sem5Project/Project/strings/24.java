 class Main {
    public static void main(String[] args) {
        String str = "programming"; // input string
        int[] freq = new int[256]; // array to store character counts

        // count frequency of each character
        for (char c : str.toCharArray()) {
            freq[c]++;
        }

        System.out.println("Duplicate characters in the string:");
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 1) { // if frequency > 1, it's a duplicate
                System.out.println((char) i + " - " + freq[i] + " times");
            }
        }
    }
}
