
// 8. Write a Java program to connect the Java API to Database, if connection not successful then throw an exception
import java.sql.*;

class DatabaseConnectionException extends Exception {
    public DatabaseConnectionException(String message) {
        super(message);
    }
}

class a {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        try {

            Class.forName("com.mysql.cj.jdbc.Driver");

            Connection con = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/java_db",
                    "root",
                    "root12");

            if (con == null) {
                throw new DatabaseConnectionException("❌ Connection not successful!");
            }

            Statement sc = con.createStatement();
            int a = 11;
            String st = "Harry";

            int x = sc.executeUpdate("INSERT INTO java_work (roll, name) VALUES (" + a + ", '" + st + "')");
            System.out.println("✅ Insert successful: " + x);

            con.close();

        } catch (DatabaseConnectionException e) {
            System.out.println(e.getMessage());
        } catch (SQLException e) {
            System.out.println("❌ SQL Error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("❌ Unexpected Error: " + e.getMessage());
        }
    }
}

// output :

// Connection failed java.lang.ClassNotFoundException: com.mysql.cj.jdbc.Driver
