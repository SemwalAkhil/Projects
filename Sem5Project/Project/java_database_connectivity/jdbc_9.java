// CODE:-

import java.sql.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/bca2ndyear_4090", "root", "root");

            // ------------------ SHOW TABLE ------------------
            System.out.println("----- Current Table -----");
            PreparedStatement psShow = c.prepareStatement("SELECT * FROM java");
            ResultSet rs = psShow.executeQuery();
            System.out.println("Rollno\tName");
            System.out.println("-----------------------");
            while (rs.next()) {
                System.out.println(rs.getInt("Rollno") + "\t" + rs.getString("Name"));
            }
            rs.close();
            psShow.close();

            // ------------------ INSERT ROW ------------------
            System.out.println("\n----- Insert New Row -----");
            System.out.print("Enter Rollno: ");
            int insertRoll = sc.nextInt();
            sc.nextLine(); // consume newline
            System.out.print("Enter Name: ");
            String insertName = sc.nextLine();

            PreparedStatement psInsert = c.prepareStatement("INSERT INTO java (Rollno, Name) VALUES (?, ?)");
            psInsert.setInt(1, insertRoll);
            psInsert.setString(2, insertName);
            int insertCount = psInsert.executeUpdate();
            System.out.println(insertCount + " row inserted successfully!");
            psInsert.close();

            // ------------------ UPDATE ROW ------------------
            System.out.println("\n----- Update Row -----");
            System.out.print("Enter Rollno to update: ");
            int updateRoll = sc.nextInt();
            sc.nextLine(); // consume newline
            System.out.print("Enter new Name: ");
            String updateName = sc.nextLine();

            PreparedStatement psUpdate = c.prepareStatement("UPDATE java SET Name=? WHERE Rollno=?");
            psUpdate.setString(1, updateName);
            psUpdate.setInt(2, updateRoll);
            int updateCount = psUpdate.executeUpdate();
            System.out.println(updateCount + " row updated successfully!");
            psUpdate.close();

            // ------------------ DELETE ROW ------------------
            System.out.println("\n----- Delete Row -----");
            System.out.print("Enter Rollno to delete: ");
            int deleteRoll = sc.nextInt();

            PreparedStatement psDelete = c.prepareStatement("DELETE FROM java WHERE Rollno=?");
            psDelete.setInt(1, deleteRoll);
            int deleteCount = psDelete.executeUpdate();
            System.out.println(deleteCount + " row deleted successfully!");
            psDelete.close();

            // ------------------ SHOW UPDATED TABLE ------------------
            System.out.println("\n----- Updated Table -----");
            PreparedStatement psFinal = c.prepareStatement("SELECT * FROM java");
            ResultSet rsFinal = psFinal.executeQuery();
            System.out.println("Rollno\tName");
            System.out.println("-----------------------");
            while (rsFinal.next()) {
                System.out.println(rsFinal.getInt("Rollno") + "\t" + rsFinal.getString("Name"));
            }
            rsFinal.close();
            psFinal.close();

        } catch (ClassNotFoundException e) {
            System.out.println("Driver not found: " + e);
        } catch (SQLException e) {
            System.out.println("SQL Error: " + e);
        }
    }
}

