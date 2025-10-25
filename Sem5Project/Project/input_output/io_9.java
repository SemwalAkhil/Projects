// CODE:-

import java.io.*;

class Main {
    public static void main(String[] args) {
        try {
            FileReader fr = new FileReader("input.txt"); // make sure input.txt exists

            int ch;
            System.out.println("File content:");
            // Read characters one by one until end of file
            while ((ch = fr.read()) != -1) {
                System.out.print((char) ch);
            }

        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + e);
        } catch (IOException e) {
            System.out.println("IO Error: " + e);
        }
    }
}
