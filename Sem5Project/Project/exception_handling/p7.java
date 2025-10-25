// 7. Write a Java program to create a method that takes a string as input and throws an exception if the string does not contain vowels.

// takes string arguments from user.
// throgh error to user if not != vowel

import java.util.*;

class NoVowelException extends Exception {
    public NoVowelException(String message) {
        super(message);
    }
}

class a {

    static void checkVowels(String str) throws NoVowelException {
        String lower = str.toLowerCase();
        if (!(lower.contains("a") || lower.contains("e") || lower.contains("i") || lower.contains("o")
                || lower.contains("u"))) {
            throw new NoVowelException("String does not contain any vowels!");
        }
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter a string: ");
            String input = sc.nextLine();
            sc.close();

            checkVowels(input);
            System.out.println("String contains vowels.");
        } catch (NoVowelException e) {
            System.out.println(e.getMessage());
        }
    }
}

/**
 * PS E:\0. Java Website Programs\Exception handling> javac .\seven.java
 * PS E:\0. Java Website Programs\Exception handling> java a
 * Enter a string: krish
 * String contains vowels.
 * PS E:\0. Java Website Programs\Exception handling> javac .\seven.java
 * PS E:\0. Java Website Programs\Exception handling> java a
 * Enter a string: myth
 * String does not contain any vowels!
 * 
 * 
 */
