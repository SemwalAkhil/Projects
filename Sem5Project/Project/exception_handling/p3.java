//  Write a Java program to create a method that reads a file and throws an exception if the file is not found.

import java.io.*;
import java.util.Scanner;

class a {
    public static void main(String[] args) {
        try {
            File file = new File("abc.txt");
            Scanner Reader = new Scanner(file);
            while (Reader.hasNextLine()) {
                String data = Reader.nextLine();
                System.out.println(data);
            }

            Reader.close();

        } catch (FileNotFoundException e) {
            System.out.println(e);
        }

        catch (Exception e) {
            System.out.println(e);
        }

    }
}
