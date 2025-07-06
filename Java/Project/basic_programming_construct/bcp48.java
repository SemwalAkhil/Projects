import java.util.*;

// 48. Java Program To Calculate Batting Average
public class bcp48 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter total runs scored : ");
        int runs = scanner.nextInt();
        System.out.print("Enter number of times batsman got out : ");
        int outs = scanner.nextInt();
        System.out.println("Batting average = %.2f".formatted((float) runs / outs));
        scanner.close();
    }
}
