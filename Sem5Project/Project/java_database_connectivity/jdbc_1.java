// CODE:-

import java.sql.*;

class Main {
    public static void main(String s[]) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/bca2ndyear_4090", "root",
                    "root");
            System.out.println("MYSQL Connected Successfully");

        } catch (ClassNotFoundException e) {
            System.out.println(e);
        } catch (SQLException e) {
            System.out.println(e);
        }
    }

}
