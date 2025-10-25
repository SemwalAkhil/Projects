// CODE:-

import java.sql.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/bca2ndyear_4090", "root", "root");
            Statement st = c.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
            ResultSet rs = st.executeQuery("SELECT * FROM java");

            System.out.println("----- Insert a New Row -----");
            System.out.print("Enter Rollno: ");
            int newRoll = sc.nextInt();
            sc.nextLine(); // consume newline
            System.out.print("Enter Name: ");
            String newName = sc.nextLine();

            rs.moveToInsertRow();
            rs.updateInt("Rollno", newRoll);
            rs.updateString("Name", newName);
            rs.insertRow();
            System.out.println("New row inserted successfully!");

            System.out.println("\n----- Update an Existing Row -----");
            System.out.print("Enter Rollno of the row to update: ");
            int updateRoll = sc.nextInt();
            sc.nextLine(); // consume newline
            System.out.print("Enter new Name: ");
            String updatedName = sc.nextLine();

            boolean foundUpdate = false;
            rs.beforeFirst();
            while (rs.next()) {
                if (rs.getInt("Rollno") == updateRoll) {
                    rs.updateString("Name", updatedName);
                    rs.updateRow();
                    System.out.println("Row updated successfully!");
                    foundUpdate = true;
                    break;
                }
            }
            if (!foundUpdate) {
                System.out.println("Rollno not found to update.");
            }

            System.out.println("\n----- Delete a Row -----");
            System.out.print("Enter Rollno of the row to delete: ");
            int deleteRoll = sc.nextInt();

            boolean foundDelete = false;
            rs.beforeFirst();
            while (rs.next()) {
                if (rs.getInt("Rollno") == deleteRoll) {
                    rs.deleteRow();
                    System.out.println("Row deleted successfully!");
                    foundDelete = true;
                    break;
                }
            }
            if (!foundDelete) {
                System.out.println("Rollno not found to delete.");
            }

            // Display updated table
            System.out.println("\n----- Updated Table -----");
            rs.beforeFirst();
            System.out.println("Rollno\tName");
            System.out.println("---------------------");
            while (rs.next()) {
                System.out.println(rs.getInt("Rollno") + "\t" + rs.getString("Name"));
            }

        } catch (ClassNotFoundException e) {
            System.out.println("Driver not found: " + e);
        } catch (SQLException e) {
            System.out.println("SQL Error: " + e);
        }
    }
}

