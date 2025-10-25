// CODE:-

import java.sql.*;

class Main {
    public static void main(String s[]) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/bca2ndyear_4090", "root",
                    "root");
            Statement st = c.createStatement();
            int x = st.executeUpdate("insert into java values (4090, 'Gagandeep Singh')");

            if (x != 0) {
                System.out.println(x + " record inserted successfully");
            }
        } catch (ClassNotFoundException e) {
            System.out.println(e);
        } catch (SQLException e) {
            System.out.println(e);
        }
    }

}
