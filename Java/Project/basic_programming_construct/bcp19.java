import java.util.*;

// 19. Write a Java program to convert seconds to hour, minute and seconds
public class bcp19 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter time in seconds : ");
        int x = scanner.nextInt();
        int min = x / 60;
        int hour = min / 60;
        min = min % 60;
        int second = x % 60;
        System.out.println("%d s is %d H %d min %d s".formatted(x, hour, min, second));
        scanner.close();
    }
}
