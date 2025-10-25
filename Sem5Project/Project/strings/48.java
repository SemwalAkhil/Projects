import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        // Use LinkedHashMap to maintain insertion order
        Map<Character, Integer> countMap = new LinkedHashMap<>();

        // Count occurrences of each character
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            countMap.put(ch, countMap.getOrDefault(ch, 0) + 1);
        }

        // Find first non-repeated character
        char firstNonRepeated = '\0';
        for (Map.Entry<Character, Integer> entry : countMap.entrySet()) {
            if (entry.getValue() == 1) {
                firstNonRepeated = entry.getKey();
                break;
            }
        }

        if (firstNonRepeated != '\0') {
            System.out.println("First non-repeated character: " + firstNonRepeated);
        } else {
            System.out.println("No non-repeated character found.");
        }

        sc.close();
    }
}
