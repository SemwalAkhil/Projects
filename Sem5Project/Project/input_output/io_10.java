// CODE:-

import java.io.*;

class Main {
    public static void main(String[] args) {
        int charCount = 0;
        int wordCount = 0;
        int lineCount = 0;

        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt")); // make sure file exists
            String line;

            System.out.println("File content:");
            while ((line = br.readLine()) != null) {
                System.out.println(line); 
                lineCount++; 
                charCount += line.length(); 
                String[] words = line.trim().split("\\s+"); 
                if (!line.trim().isEmpty()) {
                    wordCount += words.length; 
                }
            }

            // Display counts
            System.out.println("\nTotal Lines: " + lineCount);
            System.out.println("Total Words: " + wordCount);
            System.out.println("Total Characters: " + charCount);

        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + e);
        } catch (IOException e) {
            System.out.println("IO Error: " + e);
        }
    }
}
