// CODE:- 

import java.io.*;

class Main {
    public static void main(String[] args) {
        try {
            InputStreamReader isr = new InputStreamReader(System.in);
            System.out.print("Enter a character: ");

            // Read a single character
            char ch = (char) isr.read();

            System.out.println("You entered: " + ch);

        } catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }
}

