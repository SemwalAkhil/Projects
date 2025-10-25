/*19. Write a Java program to create a class with methods to search for flights and hotels,
    and to book and cancel reservations.*/

import java.io.*;

class p19 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TravelSystem ts = new TravelSystem(); // Create TravelSystem object

        while(true) {
            System.out.println("\n1. Search Flight\n2. Search Hotel\n3. Book Flight\n4. Cancel Flight\n5. Book Hotel\n6. Cancel Hotel\n7. Display Reservations\n8. Exit");
            System.out.print("Enter your choice: ");
            int choice = Integer.parseInt(br.readLine());

            switch(choice) {
                case 1:
                    System.out.print("Enter flight name to search: ");
                    String flightSearch = br.readLine();
                    ts.searchFlight(flightSearch);
                    break;
                case 2:
                    System.out.print("Enter hotel name to search: ");
                    String hotelSearch = br.readLine();
                    ts.searchHotel(hotelSearch);
                    break;
                case 3:
                    System.out.print("Enter flight name to book: ");
                    String flightBook = br.readLine();
                    ts.bookFlight(flightBook);
                    break;
                case 4:
                    System.out.print("Enter flight name to cancel: ");
                    String flightCancel = br.readLine();
                    ts.cancelFlight(flightCancel);
                    break;
                case 5:
                    System.out.print("Enter hotel name to book: ");
                    String hotelBook = br.readLine();
                    ts.bookHotel(hotelBook);
                    break;
                case 6:
                    System.out.print("Enter hotel name to cancel: ");
                    String hotelCancel = br.readLine();
                    ts.cancelHotel(hotelCancel);
                    break;
                case 7:
                    ts.displayReservations();
                    break;
                case 8:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}

// TravelSystem class managing flights, hotels, and reservations
class TravelSystem {
    private String[] flights;        // Available flights
    private String[] hotels;         // Available hotels
    private String[] bookedFlights;  // Booked flights
    private String[] bookedHotels;   // Booked hotels
    private int flightCount, hotelCount, bookedFlightCount, bookedHotelCount;

    TravelSystem() {
        flights = new String[]{"FlightA", "FlightB", "FlightC"}; // Sample flights
        hotels = new String[]{"HotelX", "HotelY", "HotelZ"};     // Sample hotels
        bookedFlights = new String[50];
        bookedHotels = new String[50];
        flightCount = flights.length;
        hotelCount = hotels.length;
        bookedFlightCount = bookedHotelCount = 0;
    }

    // Search for a flight
    void searchFlight(String name) {
        for(int i = 0; i < flightCount; i++) {
            if(flights[i].equalsIgnoreCase(name)) {
                System.out.println(name + " is available.");
                return;
            }
        }
        System.out.println(name + " not found.");
    }

    // Search for a hotel
    void searchHotel(String name) {
        for(int i = 0; i < hotelCount; i++) {
            if(hotels[i].equalsIgnoreCase(name)) {
                System.out.println(name + " is available.");
                return;
            }
        }
        System.out.println(name + " not found.");
    }

    // Book a flight
    void bookFlight(String name) {
        for(int i = 0; i < flightCount; i++) {
            if(flights[i].equalsIgnoreCase(name)) {
                bookedFlights[bookedFlightCount++] = name;
                System.out.println(name + " booked successfully.");
                return;
            }
        }
        System.out.println(name + " not available to book.");
    }

    // Cancel a booked flight
    void cancelFlight(String name) {
        boolean found = false;
        for(int i = 0; i < bookedFlightCount; i++) {
            if(bookedFlights[i].equalsIgnoreCase(name)) {
                for(int j = i; j < bookedFlightCount - 1; j++) {
                    bookedFlights[j] = bookedFlights[j + 1];
                }
                bookedFlights[--bookedFlightCount] = null;
                System.out.println(name + " booking cancelled.");
                found = true;
                break;
            }
        }
        if(!found) System.out.println(name + " not found in booked flights.");
    }

    // Book a hotel
    void bookHotel(String name) {
        for(int i = 0; i < hotelCount; i++) {
            if(hotels[i].equalsIgnoreCase(name)) {
                bookedHotels[bookedHotelCount++] = name;
                System.out.println(name + " booked successfully.");
                return;
            }
        }
        System.out.println(name + " not available to book.");
    }

    // Cancel a booked hotel
    void cancelHotel(String name) {
        boolean found = false;
        for(int i = 0; i < bookedHotelCount; i++) {
            if(bookedHotels[i].equalsIgnoreCase(name)) {
                for(int j = i; j < bookedHotelCount - 1; j++) {
                    bookedHotels[j] = bookedHotels[j + 1];
                }
                bookedHotels[--bookedHotelCount] = null;
                System.out.println(name + " booking cancelled.");
                found = true;
                break;
            }
        }
        if(!found) System.out.println(name + " not found in booked hotels.");
    }

    // Display all booked flights and hotels
    void displayReservations() {
        System.out.println("\nBooked Flights:");
        if(bookedFlightCount == 0) System.out.println("None");
        else {
            for(int i = 0; i < bookedFlightCount; i++) {
                System.out.println((i + 1) + ". " + bookedFlights[i]);
            }
        }

        System.out.println("Booked Hotels:");
        if(bookedHotelCount == 0) System.out.println("None");
        else {
            for(int i = 0; i < bookedHotelCount; i++) {
                System.out.println((i + 1) + ". " + bookedHotels[i]);
            }
        }
    }
}
