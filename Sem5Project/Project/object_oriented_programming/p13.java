/*13. Write a Java program to create a class called "Inventory" with a collection of products,
    and methods to add and remove products, and to check for low inventory.*/

import java.io.*;

class p13 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Inventory inv = new Inventory(); // Create Inventory object

        while(true) {
            System.out.println("\n1. Add Product\n2. Remove Product\n3. Display Products\n4. Check Low Inventory\n5. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            if(choice == 1) {
                System.out.print("Enter product name: ");
                String name = br.readLine();
                System.out.print("Enter product quantity: ");
                int qty = Integer.parseInt(br.readLine());
                inv.addProduct(name, qty);
            } else if(choice == 2) {
                System.out.print("Enter product name to remove: ");
                String name = br.readLine();
                inv.removeProduct(name);
            } else if(choice == 3) {
                inv.displayProducts();
            } else if(choice == 4) {
                System.out.print("Enter low inventory threshold: ");
                int threshold = Integer.parseInt(br.readLine());
                inv.checkLowInventory(threshold);
            } else if(choice == 5) {
                System.out.println("Exiting...");
                break;
            } else {
                System.out.println("Invalid choice!");
            }
        }
    }
}

// Product class represents individual products
class Product {
    String name;
    int quantity;

    Product(String n, int q) {
        name = n;
        quantity = q;
    }
}

// Inventory class manages a collection of products using array
class Inventory {
    private Product[] products; // Array to store products
    private int productCount;   // Number of products in inventory

    Inventory() {
        products = new Product[50]; // Maximum 50 products
        productCount = 0;
    }

    // Method to add a product
    void addProduct(String name, int qty) {
        if(productCount >= 50) {
            System.out.println("Cannot add more products. Inventory full.");
            return;
        }
        // Check if product already exists; if so, increase quantity
        for(int i = 0; i < productCount; i++) {
            if(products[i].name.equalsIgnoreCase(name)) {
                products[i].quantity += qty;
                System.out.println(name + " quantity updated. New quantity: " + products[i].quantity);
                return;
            }
        }
        // Add new product
        products[productCount++] = new Product(name, qty);
        System.out.println(name + " added to inventory with quantity " + qty);
    }

    // Method to remove a product completely
    void removeProduct(String name) {
        boolean found = false;
        for(int i = 0; i < productCount; i++) {
            if(products[i].name.equalsIgnoreCase(name)) {
                // Shift remaining products left
                for(int j = i; j < productCount - 1; j++) {
                    products[j] = products[j + 1];
                }
                products[--productCount] = null;
                System.out.println(name + " removed from inventory.");
                found = true;
                break;
            }
        }
        if(!found) {
            System.out.println(name + " not found in inventory.");
        }
    }

    // Method to display all products and quantities
    void displayProducts() {
        if(productCount == 0) {
            System.out.println("Inventory is empty.");
            return;
        }
        System.out.println("Current Inventory:");
        for(int i = 0; i < productCount; i++) {
            System.out.println((i + 1) + ". " + products[i].name + " - Quantity: " + products[i].quantity);
        }
    }

    // Method to check for low inventory
    void checkLowInventory(int threshold) {
        boolean found = false;
        System.out.println("Products below threshold " + threshold + ":");
        for(int i = 0; i < productCount; i++) {
            if(products[i].quantity < threshold) {
                System.out.println(products[i].name + " - Quantity: " + products[i].quantity);
                found = true;
            }
        }
        if(!found) {
            System.out.println("No products below threshold.");
        }
    }
}
