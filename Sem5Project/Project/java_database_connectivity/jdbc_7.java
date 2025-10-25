// CODE:-

import java.sql.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/bca2ndyear_4090", "root", "root");
            Statement st = c.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM java");

            // Ask user for row number
            System.out.print("Enter the row number to display: ");
            int rowNumber = sc.nextInt();

            // Move cursor to the requested row
            if (rs.absolute(rowNumber)) { 
                System.out.println("Rollno: " + rs.getInt("Rollno"));
                System.out.println("Name: " + rs.getString("Name"));
            } else {
                System.out.println("Row number " + rowNumber + " does not exist.");
            }

        } catch (ClassNotFoundException e) {
            System.out.println("Driver not found: " + e);
        } catch (SQLException e) {
            System.out.println("SQL Error: " + e);
        }
    }
}

