/*12. Write a Java program to create a class called "Airplane" with a flight number,
    destination, and departure time attributes, and methods to check flight status and delay.*/

import java.io.*;

class p12 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read flight number
        System.out.print("Enter Flight Number: ");
        String flightNo = br.readLine();

        // Read destination
        System.out.print("Enter Destination: ");
        String dest = br.readLine();

        // Read departure time in HH:MM format
        System.out.print("Enter Departure Time (HH:MM): ");
        String depTime = br.readLine();

        // Create Airplane object
        Airplane a1 = new Airplane(flightNo, dest, depTime);

        a1.displayDetails();

        // Check flight status
        System.out.print("\nIs the flight delayed? (yes/no): ");
        String delayed = br.readLine();
        if(delayed.equalsIgnoreCase("yes")) {
            System.out.print("Enter delay in minutes: ");
            int delayMin = Integer.parseInt(br.readLine());
            a1.addDelay(delayMin);
        }

        a1.displayStatus();
    }
}

// Airplane class with flight number, destination, departure time, and delay
class Airplane {
    private String flightNumber;
    private String destination;
    private String departureTime; // HH:MM
    private int delayMinutes;     // Delay in minutes

    // Constructor initializes attributes
    Airplane(String fn, String dest, String depTime) {
        flightNumber = fn;
        this.destination = dest;
        this.departureTime = depTime;
        delayMinutes = 0; // No delay initially
    }

    // Method to add delay in minutes
    void addDelay(int minutes) {
        if(minutes < 0) {
            System.out.println("Invalid delay time.");
            return;
        }
        delayMinutes += minutes;
        System.out.println("Delay updated by " + minutes + " minutes.");
    }

    // Method to display flight details
    void displayDetails() {
        System.out.println("\nFlight Details:");
        System.out.println("Flight Number: " + flightNumber);
        System.out.println("Destination: " + destination);
        System.out.println("Scheduled Departure: " + departureTime);
    }

    // Method to display current flight status
    void displayStatus() {
        if(delayMinutes == 0) {
            System.out.println("Flight is on time.");
        } else {
            System.out.println("Flight delayed by " + delayMinutes + " minutes.");
        }
    }
}
