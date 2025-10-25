/*15. Write a Java program to create a class called "MusicLibrary" with a collection of songs,
    and methods to add and remove songs, and to play a random song.*/

import java.io.*;
import java.util.Random;

class p15 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        MusicLibrary lib = new MusicLibrary(); // Create MusicLibrary object
        Random rand = new Random();

        while(true) {
            System.out.println("\n1. Add Song\n2. Remove Song\n3. Display Songs\n4. Play Random Song\n5. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            switch(choice) {
                case 1:
                    System.out.print("Enter song name: ");
                    String songName = br.readLine();
                    lib.addSong(songName);
                    break;
                case 2:
                    System.out.print("Enter song name to remove: ");
                    String removeSong = br.readLine();
                    lib.removeSong(removeSong);
                    break;
                case 3:
                    lib.displaySongs();
                    break;
                case 4:
                    lib.playRandomSong(rand);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}

// MusicLibrary class using fixed-size array for storing songs
class MusicLibrary {
    private String[] songs;  // Array to store song names
    private int songCount;   // Number of songs currently in library

    MusicLibrary() {
        songs = new String[50]; // Maximum 50 songs
        songCount = 0;
    }

    // Method to add a song
    void addSong(String name) {
        if(songCount >= 50) {
            System.out.println("Cannot add more songs. Library full.");
            return;
        }
        for(int i = 0; i < songCount; i++) {
            if(songs[i].equalsIgnoreCase(name)) {
                System.out.println(name + " is already in the library.");
                return;
            }
        }
        songs[songCount++] = name;
        System.out.println(name + " added to library.");
    }

    // Method to remove a song
    void removeSong(String name) {
        boolean found = false;
        for(int i = 0; i < songCount; i++) {
            if(songs[i].equalsIgnoreCase(name)) {
                for(int j = i; j < songCount - 1; j++) {
                    songs[j] = songs[j + 1];
                }
                songs[--songCount] = null;
                System.out.println(name + " removed from library.");
                found = true;
                break;
            }
        }
        if(!found) {
            System.out.println(name + " not found in library.");
        }
    }

    // Method to display all songs
    void displaySongs() {
        if(songCount == 0) {
            System.out.println("Library is empty.");
            return;
        }
        System.out.println("Songs in Library:");
        for(int i = 0; i < songCount; i++) {
            System.out.println((i + 1) + ". " + songs[i]);
        }
    }

    // Method to play a random song
    void playRandomSong(Random rand) {
        if(songCount == 0) {
            System.out.println("Library is empty. Cannot play any song.");
            return;
        }
        int index = rand.nextInt(songCount); // Random index
        System.out.println("Now playing: " + songs[index]);
    }
}
