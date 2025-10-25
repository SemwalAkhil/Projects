 class Main{
    public static void main(String[] args) {
        String str = "this is a test this is only a test"; // input string
        str = str.toLowerCase(); // convert to lowercase for consistency

        String[] words = str.split(" "); // split string into words
        int count;

        System.out.println("Duplicate words in the string:");

        for (int i = 0; i < words.length; i++) {
            count = 1;
            if (words[i].equals("0")) // skip words already marked
                continue;

            for (int j = i + 1; j < words.length; j++) {
                if (words[i].equals(words[j])) {
                    count++;
                    words[j] = "0"; // mark as counted
                }
            }

            if (count > 1)
                System.out.println(words[i] + " - " + count + " times");
        }
    }
}
