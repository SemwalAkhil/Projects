import java.io.*;
import java.util.*;

 class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("input.txt")); // read file
        Map<String, Integer> map = new HashMap<>();

        while (sc.hasNext()) {
            String word = sc.next().toLowerCase().replaceAll("[^a-z]", ""); // remove punctuation
            if (word.isEmpty()) continue;
            map.put(word, map.getOrDefault(word, 0) + 1); // count frequency
        }
        sc.close();

        String maxWord = "";
        int maxCount = 0;
        for (String w : map.keySet()) {
            if (map.get(w) > maxCount) {
                maxCount = map.get(w);
                maxWord = w;
            }
        }

        System.out.println("Most repeated word: " + maxWord);
        System.out.println("Frequency: " + maxCount);
    }
}
