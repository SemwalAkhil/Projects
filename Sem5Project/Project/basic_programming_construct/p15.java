//15. Write a Java program to display the system time
import java.time.*;

class Main
{
    public static void main(String args[]) 
    {
        LocalTime lc = LocalTime.now();
        System.out.println("Hours:Minutes:Seconds.NanoSeconds");
        System.out.println("HH:MM:SS.NS");
        System.out.println(lc);
    }
}
