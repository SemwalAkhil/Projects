// CODE:-

import java.sql.*;

class Main {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/bca2ndyear_4090", "root", "root");
            Statement st = c.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM java");

            // Display results
            System.out.println("Rollno\tName");
            System.out.println("----------------------");
            while (rs.next()) {
                int rollno = rs.getInt("Rollno");
                String name = rs.getString("Name");
                System.out.println(rollno + "\t" + name);
            }

        } catch (ClassNotFoundException e) {
            System.out.println("Driver not found: " + e);
        } catch (SQLException e) {
            System.out.println("SQL Error: " + e);
        }
    }
}

