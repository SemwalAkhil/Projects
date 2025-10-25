import java.sql.*;
class temp{
	public static void main(String st[]){
		Connection c;
		Statement s;
		int x,rollInt;
		String roll,name;
		ResultSet rs;
		try{
			Class.forName("com.mysql.cj.jdbc.Driver");
			c = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb","root","root");
			s = c.createStatement();
			try
			{
				
				java.io.InputStreamReader ip=new java.io.InputStreamReader(System.in);
				java.io.BufferedReader br=new java.io.BufferedReader(ip);
				System.out.print("enter the roll number: ");
				roll=br.readLine();
				System.out.print("enter the name: ");
				name=br.readLine();
				System.out.println("insert into mytable values (" + roll + ", '" + name + "');");
				x = s.executeUpdate("insert into mytable values (" + roll + ", '" + name + "');");
				try{
					rs = s.executeQuery("select * from mytable;");
					while (rs.next()){
						int c1 = rs.getInt(1);
						String c2 = rs.getString(2);
						System.out.println(c1+" "+c2);	

					}
				}
				catch (SQLException e){
					System.out.print("An exception occured : " + e.getMessage());
				}
			}
			catch(Exception e){
				System.out.print(e);
			}
			
		}
		catch (Exception e){
			System.out.println(e);
		}
	}
}

