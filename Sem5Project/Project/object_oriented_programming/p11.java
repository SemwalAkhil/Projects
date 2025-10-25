/*11. Write a Java program to create a class called "Library" with a collection of books
    and methods to add and remove books.*/

import java.io.*;

class p11 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Library lib = new Library(); // Create Library object

        while(true) {
            System.out.println("\n1. Add Book\n2. Remove Book\n3. Display Books\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            if(choice == 1) {
                System.out.print("Enter book name to add: ");
                String book = br.readLine();
                lib.addBook(book); // Add book to library
            } else if(choice == 2) {
                System.out.print("Enter book name to remove: ");
                String book = br.readLine();
                lib.removeBook(book); // Remove book from library
            } else if(choice == 3) {
                lib.displayBooks(); // Display all books
            } else if(choice == 4) {
                System.out.println("Exiting...");
                break; // Exit loop
            } else {
                System.out.println("Invalid choice!");
            }
        }
    }
}

// Library class using fixed-size array to store books
class Library {
    private String[] books;  // Array to store book names
    private int bookCount;   // Number of books currently in library

    // Constructor initializes array and count
    Library() {
        books = new String[50]; // Maximum 50 books
        bookCount = 0;
    }

    // Method to add a book
    void addBook(String book) {
        // Check if library is full
        if(bookCount >= 50) {
            System.out.println("Cannot add more books. Library is full.");
            return;
        }
        // Check if book already exists
        for(int i = 0; i < bookCount; i++) {
            if(books[i].equalsIgnoreCase(book)) {
                System.out.println(book + " already exists in the library.");
                return;
            }
        }
        books[bookCount++] = book; // Add book and increment count
        System.out.println(book + " added to library.");
    }

    // Method to remove a book
    void removeBook(String book) {
        boolean found = false;
        for(int i = 0; i < bookCount; i++) {
            if(books[i].equalsIgnoreCase(book)) {
                // Shift remaining books left
                for(int j = i; j < bookCount - 1; j++) {
                    books[j] = books[j + 1];
                }
                books[--bookCount] = null; // Clear last element
                System.out.println(book + " removed from library.");
                found = true;
                break;
            }
        }
        if(!found) {
            System.out.println(book + " not found in library.");
        }
    }

    // Method to display all books
    void displayBooks() {
        if(bookCount == 0) {
            System.out.println("Library is empty.");
            return;
        }
        System.out.println("Books in library:");
        for(int i = 0; i < bookCount; i++) {
            System.out.println((i + 1) + ". " + books[i]);
        }
    }
}
