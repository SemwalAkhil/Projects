/*17. Write a Java program to create a class called "Movie" with attributes for title,
    director, actors, and reviews, and methods for adding and retrieving reviews.*/

import java.io.*;

class p17 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read movie details
        System.out.print("Enter Movie Title: ");
        String title = br.readLine();

        System.out.print("Enter Director Name: ");
        String director = br.readLine();

        // Read number of actors
        System.out.print("Enter number of actors: ");
        int numActors = Integer.parseInt(br.readLine());
        String[] actors = new String[numActors];

        for(int i = 0; i < numActors; i++) {
            System.out.print("Enter actor " + (i+1) + " name: ");
            actors[i] = br.readLine();
        }

        Movie movie = new Movie(title, director, actors);

        while(true) {
            System.out.println("\n1. Add Review\n2. Show Reviews\n3. Display Movie Info\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            switch(choice) {
                case 1:
                    System.out.print("Enter review: ");
                    String review = br.readLine();
                    movie.addReview(review);
                    break;
                case 2:
                    movie.showReviews();
                    break;
                case 3:
                    movie.displayMovieInfo();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}

// Movie class with title, director, actors, and reviews
class Movie {
    private String title;
    private String director;
    private String[] actors;     // Fixed array for actors
    private String[] reviews;    // Fixed array for reviews
    private int reviewCount;

    Movie(String t, String d, String[] a) {
        title = t;
        director = d;
        actors = a;
        reviews = new String[50]; // Maximum 50 reviews
        reviewCount = 0;
    }

    // Add a review to the movie
    void addReview(String review) {
        if(reviewCount >= 50) {
            System.out.println("Cannot add more reviews. Limit reached.");
            return;
        }
        reviews[reviewCount++] = review;
        System.out.println("Review added.");
    }

    // Display all reviews
    void showReviews() {
        if(reviewCount == 0) {
            System.out.println("No reviews available.");
            return;
        }
        System.out.println("Reviews for " + title + ":");
        for(int i = 0; i < reviewCount; i++) {
            System.out.println((i + 1) + ". " + reviews[i]);
        }
    }

    // Display movie information
    void displayMovieInfo() {
        System.out.println("\nMovie Title: " + title);
        System.out.println("Director: " + director);
        System.out.print("Actors: ");
        for(int i = 0; i < actors.length; i++) {
            System.out.print(actors[i]);
            if(i < actors.length - 1) System.out.print(", ");
        }
        System.out.println();
    }
}
