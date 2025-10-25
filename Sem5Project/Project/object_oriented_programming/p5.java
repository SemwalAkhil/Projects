/* 
5. Write a Java program to create a class called "Book" with attributes for title, author, and ISBN, and methods to add and remove books from a collection. 
*/
class p5 {
    public static void main(String st[]) {
        // Create a Collection object to store books (capacity = 3)
        Collection c1 = new Collection(3);

        // Adding and removing books to test functionality
        c1.addbook(new Book("The Silent Patient", "Alex Michaelides", "9781250301697"));
        c1.removebook("9781250301697");   // remove existing book
        c1.removebook("9781250301697");   // try removing again (not found)
        c1.addbook(new Book("The Silent Patient", "Alex Michaelides", "9781250301697"));
        c1.addbook(new Book("Atomic Habits", "James Clear", "9780735211292"));
        c1.addbook(new Book("A Brief History of Humankind", "Yuval Noah Harari", "9780062316097"));
        c1.addbook(new Book("The Silent Patient", "Alex Michaelides", "9781250301697")); // duplicate ISBN
        c1.removebook("97812503016s7");   // wrong ISBN
        c1.addbook(new Book("Wings of Fire", "A. P. J. Abdul Kalam", "9788173711466")); // collection full
    }  
}

// Book class represents an entity with title, author, and ISBN
class Book {
    String title;
    String author;
    String ISBN;

    // Constructor to initialize book details
    Book(String tl, String au, String ib) {
        title = tl;
        author = au;
        ISBN = ib;
    }
}
// Collection class manages an array of Book objects
class Collection {
    Book books[]; // array to store books
    int cur;      // current count of books
    Collection(int size) { 
        books = new Book[size];
        cur = 0;
    
    // Search book by ISBN, return index if found, else -1
    int searchbook(String Ib) {
        for (int i = 0; i < cur; i++) {
            if (books[i].ISBN.equals(Ib)) {
                return i;
            }
        }
        return -1;
    }
    // Add book only if ISBN not already present and space available
    void addbook(Book bk) {
        if (searchbook(bk.ISBN) == -1) {
            if (cur < books.length) {
                books[cur++] = bk;
                System.out.println("Book added having ISBN : " + bk.ISBN);
            } else {
                System.out.println("Collection full");
            }
        } else {
            System.out.println("Book with ISBN : " + bk.ISBN + " already in collection");
        }
    }
    // Remove book by ISBN, shift remaining books to fill gap
    void removebook(String Ib) {
        if (cur == 0) {
            System.out.println("No book in collection to remove");
        } else {
            int bookix = searchbook(Ib);
            if (bookix == -1) {
                System.out.println("No book found having ISBN: " + Ib + " in the collection");
            } else {
                for (int i = bookix; i < cur - 1; i++) { // shift left
                    books[i] = books[i + 1];
                }
                books[--cur] = null; // reduce size and free slot
                System.out.println("Book having ISBN: " + Ib + " removed from the collection");
            }
        }
    }
}
}