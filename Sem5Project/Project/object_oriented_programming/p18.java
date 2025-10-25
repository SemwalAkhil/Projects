/*18. Write a Java program to create a class called "Restaurant" with attributes for 
    menu items, prices, and ratings, and methods to add and remove items, and to calculate average rating.*/

import java.io.*;

class p18 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Restaurant res = new Restaurant(); // Create Restaurant object

        while(true) {
            System.out.println("\n1. Add Menu Item\n2. Remove Menu Item\n3. Display Menu\n4. Average Rating\n5. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            switch(choice) {
                case 1:
                    System.out.print("Enter item name: ");
                    String name = br.readLine();
                    System.out.print("Enter item price: ");
                    double price = Double.parseDouble(br.readLine());
                    System.out.print("Enter item rating (1-5): ");
                    double rating = Double.parseDouble(br.readLine());
                    res.addItem(name, price, rating);
                    break;
                case 2:
                    System.out.print("Enter item name to remove: ");
                    String removeName = br.readLine();
                    res.removeItem(removeName);
                    break;
                case 3:
                    res.displayMenu();
                    break;
                case 4:
                    System.out.println("Average Rating: " + res.averageRating());
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

// Restaurant class using fixed-size arrays
class Restaurant {
    private String[] items;     // Menu item names
    private double[] prices;    // Prices of items
    private double[] ratings;   // Ratings of items
    private int itemCount;      // Current number of items

    Restaurant() {
        items = new String[50];   // Max 50 items
        prices = new double[50];
        ratings = new double[50];
        itemCount = 0;
    }

    // Add a menu item
    void addItem(String name, double price, double rating) {
        if(itemCount >= 50) {
            System.out.println("Cannot add more items. Menu full.");
            return;
        }
        for(int i = 0; i < itemCount; i++) {
            if(items[i].equalsIgnoreCase(name)) {
                System.out.println(name + " already exists in menu.");
                return;
            }
        }
        items[itemCount] = name;
        prices[itemCount] = price;
        ratings[itemCount] = rating;
        itemCount++;
        System.out.println(name + " added to menu.");
    }

    // Remove a menu item
    void removeItem(String name) {
        boolean found = false;
        for(int i = 0; i < itemCount; i++) {
            if(items[i].equalsIgnoreCase(name)) {
                for(int j = i; j < itemCount - 1; j++) {
                    items[j] = items[j + 1];
                    prices[j] = prices[j + 1];
                    ratings[j] = ratings[j + 1];
                }
                items[--itemCount] = null;
                prices[itemCount] = 0;
                ratings[itemCount] = 0;
                System.out.println(name + " removed from menu.");
                found = true;
                break;
            }
        }
        if(!found) {
            System.out.println(name + " not found in menu.");
        }
    }

    // Display the menu
    void displayMenu() {
        if(itemCount == 0) {
            System.out.println("Menu is empty.");
            return;
        }
        System.out.println("Menu Items:");
        for(int i = 0; i < itemCount; i++) {
            System.out.println((i + 1) + ". " + items[i] + " | Price: " + prices[i] + " | Rating: " + ratings[i]);
        }
    }

    // Calculate average rating
    double averageRating() {
        if(itemCount == 0) return 0;
        double sum = 0;
        for(int i = 0; i < itemCount; i++) {
            sum += ratings[i];
        }
        return sum / itemCount;
    }
}
