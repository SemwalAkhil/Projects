//8. Write a Java method to display the current date and time.
import java.util.Date;

class Current
{
	String currentDate()
	{
		Date d=new Date();
		return (d.getDate())+" : "+(d.getMonth()+1)+" : "+(d.getYear()+1900);
	}
	String currentTime()
	{
		Date d=new Date();
		return d.getHours()+" hours "+d.getMinutes()+" minutes "+d.getSeconds()+" seconds";
	}
}

class Main
{
	public static void main(String st[])
	{
		Current c=new Current();
		
		System.out.println("Current date : "+c.currentDate());
		System.out.println("Current Time : "+c.currentTime());
	}
}


/*
 
Output : 

Current date : 19 : 9 : 2025
Current Time : 19 hours 52 minutes 7 seconds

 */