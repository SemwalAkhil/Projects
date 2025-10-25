import java.io.*;
import java.util.*;

 class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("input.txt")); 
        int wordCount = 0;

        while (sc.hasNext()) {
            sc.next(); // read each word
            wordCount++; // increment counter
        }
        sc.close();

        System.out.println("Total number of words in the file: " + wordCount);
    }
}
