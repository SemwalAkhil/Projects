
// 4. Write a Java program that reads a list of numbers from a file and throws an exception if any of the numbers are positive.
import java.io.*;
import java.util.*;

// Custom Exception
class PositiveNumberException extends Exception {
    public PositiveNumberException(String message) {
        super(message);
    }
}

class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        File file = new File("numbers.txt");

        try {
            // Step 1: Create file if not exists
            if (!file.exists()) {
                file.createNewFile();
                System.out.println("File created: " + file.getName());
            } else {
                System.out.println("File already exists: " + file.getName());
            }

            // Step 2: Take user input and write to file
            System.out.print("Enter how many numbers you want to add: ");
            int n = sc.nextInt();

            FileWriter fw = new FileWriter(file);
            System.out.println("Enter " + n + " numbers (space separated or new line):");

            for (int i = 0; i < n; i++) {
                fw.write(sc.nextInt() + "\n");
            }
            fw.close();
            System.out.println("Numbers written to file successfully.");

            // Step 3: Read numbers from file
            Scanner fileReader = new Scanner(file);
            List<Integer> numbers = new ArrayList<>();

            while (fileReader.hasNextInt()) {
                numbers.add(fileReader.nextInt());
            }
            fileReader.close();

            // Step 4: Check for positive numbers
            for (int num : numbers) {
                if (num > 0) {
                    throw new PositiveNumberException("Positive number found: " + num);
                }
            }

            System.out.println("No positive numbers found. All numbers are zero or negative.");

        } catch (PositiveNumberException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println("Error handling file: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Unexpected error: " + e.getMessage());
        } finally {
            sc.close();
        }
    }
}

/*
 * PS E:\0. Java Website Programs\Exception handling> javac .\fourth.java
 * PS E:\0. Java Website Programs\Exception handling> java a
 * File already exists: numbers.txt
 * Enter how many numbers you want to add: 5
 * Enter 5 numbers (space separated or new line):
 * 1
 * 2
 * 3
 * 4
 * 12
 * Numbers written to file successfully.
 * Positive number found: 1
 * 
 * 
 * 
 */
