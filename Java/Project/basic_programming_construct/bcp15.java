import java.time.*;

// 15. Write a Java program to display the system time
public class bcp15 {
    public static void main(String[] args) {
        LocalTime localTime = LocalTime.now();
        System.out.println("Current system time : %d H: %d min: %d s".formatted(localTime.getHour(),
                localTime.getMinute(), localTime.getSecond()));
    }
}
