 class Main {
    public static void main(String[] args) {
        String str = "Surya Loves You ";
        String[] words = str.split(" "); 

        String largest = words[0];
        String smallest = words[0];

        for (String word : words) {
            if (word.length() > largest.length()) {
                largest = word; 
            }
            if (word.length() < smallest.length()) {
                smallest = word; 
            }
        }

        System.out.println("Largest word: " + largest);
        System.out.println("Smallest word: " + smallest);
    }
}