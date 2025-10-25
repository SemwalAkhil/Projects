// 9. Write a Java program to manage the driver with path, username and password, if not successful then throw an exception

import java.io.*;
import java.sql.*;

// Custom Exception for Database Connection Failure
class DatabaseConnectionException extends Exception {
    public DatabaseConnectionException(String message) {
        super(message);
    }
}

// Class to store user input
class InputData {
    public int roll;
    public String name;
}

 class a {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {

        InputData obj = new InputData();

        // Step 1: Take user input
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.println("Enter your roll no:");
            obj.roll = Integer.parseInt(br.readLine());

            System.out.println("Enter your name:");
            obj.name = br.readLine();

        } catch (IOException e) {
            System.out.println("❌ Input Error: " + e.getMessage());
        }

        System.out.println("The roll is: " + obj.roll);
        System.out.println("The name is: " + obj.name);

        Connection con = null;

        try {
            // Step 2: Load the JDBC Driver (managing driver path)
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("✅ Driver Loaded Successfully!");

            // Step 3: Manage username, password, and connection path
            String url = "jdbc:mysql://localhost:3306/java_db";
            String username = "root";
            String password = "root12";

            con = DriverManager.getConnection(url, username, password);

            if (con == null) {
                throw new DatabaseConnectionException("❌ Connection failed: Could not establish database connection.");
            }

            System.out.println("✅ Connection established successfully!");

            // Step 4: Create Statement and execute query
            Statement stmt = con.createStatement();
            int result = stmt.executeUpdate(
                    "INSERT INTO java_work (roll, name) VALUES (" + obj.roll + ", '" + obj.name + "')");

            System.out.println("✅ Insert successful: " + result + " row(s) affected.");

        } catch (DatabaseConnectionException e) {
            System.out.println(e.getMessage());
        } catch (SQLException e) {
            System.out.println("❌ SQL Error: " + e.getMessage());
        } catch (ClassNotFoundException e) {
            System.out.println("❌ JDBC Driver not found: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("❌ Unexpected Error: " + e.getMessage());
        } finally {
            // Step 5: Close the connection
            if (con != null) {
                con.close();
                System.out.println("🔒 Connection closed.");
            }
        }
    }
}
