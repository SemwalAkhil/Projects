// 10. Write a Java program to throw the SQL Query, insert, delete, update, if not successful then throw an exception

import java.sql.*;

// Custom Exception for SQL Operations
class SQLOperationException extends Exception {
    public SQLOperationException(String message) {
        super(message);
    }
}

// Database class to manage connection and SQL operations
class Database {
    Connection con;
    Statement stm;

    // Constructor — establishes connection
    public Database(String url, String uname, String pwd) throws ClassNotFoundException, SQLException {
        // Load the MySQL driver
        Class.forName("com.mysql.cj.jdbc.Driver");
        con = DriverManager.getConnection(url, uname, pwd);
        stm = con.createStatement();
        System.out.println("Database connected successfully.");
    }

    // Insert method
    int insert_db(String query) throws SQLException, SQLOperationException {
        int rows = stm.executeUpdate(query);
        if (rows == 0) {
            throw new SQLOperationException("Insert operation failed!");
        }
        return rows;
    }

    // Delete method
    int delete_db(String query) throws SQLException, SQLOperationException {
        int rows = stm.executeUpdate(query);
        if (rows == 0) {
            throw new SQLOperationException("Delete operation failed!");
        }
        return rows;
    }

    // Update method
    int update_db(String query) throws SQLException, SQLOperationException {
        int rows = stm.executeUpdate(query);
        if (rows == 0) {
            throw new SQLOperationException("Update operation failed!");
        }
        return rows;
    }

    // Close connection
    void close() throws SQLException {
        if (con != null) {
            con.close();
            System.out.println("Connection closed.");
        }
    }
}

// Main class
class mymain {
    public static void main(String[] args) {
        try {
            Database db1 = new Database("jdbc:mysql://localhost:3306/java_db", "root", "root12");

            int insertRes = db1.insert_db("INSERT INTO java_work (roll, name) VALUES (21, 'Rishabh')");
            System.out.println("Insert Successful: " + insertRes + " row(s) affected.");

            int updateRes = db1.update_db("UPDATE java_work SET name='Updated_Rishabh' WHERE roll=21");
            System.out.println("Update Successful: " + updateRes + " row(s) affected.");

            int deleteRes = db1.delete_db("DELETE FROM java_work WHERE roll=21");
            System.out.println("Delete Successful: " + deleteRes + " row(s) affected.");

            db1.close();

        } catch (SQLOperationException e) {
            System.out.println(e.getMessage());
        } catch (SQLException e) {
            System.out.println("SQL Error: " + e.getMessage());
        } catch (ClassNotFoundException e) {
            System.out.println("Driver not found: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Unexpected error: " + e.getMessage());
        }
    }
}

/**
 * 
 * Output :
 * 
 * PS D:\JAVA\databse connectivity in java> javac .\file.java
 * PS D:\JAVA\databse connectivity in java> java -cp
 * ".;lib/mysql-connector-j-9.4.0.jar" mymain
 * Database connected successfully.
 * Insert Successful: 1 row(s) affected.
 * Update Successful: 1 row(s) affected.
 * Delete Successful: 1 row(s) affected.
 * Connection closed.
 * 
 * 
 */
