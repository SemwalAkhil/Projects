// CODE:-

import java.io.*;

class Main {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            System.out.print("Enter a string: ");
            String input = br.readLine(); // read a line of text

            System.out.println("You entered: " + input);

        } catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }
}
