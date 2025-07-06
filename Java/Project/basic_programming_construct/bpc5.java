import java.util.Scanner;

// 5. Write a Java program that takes five numbers as input to calculate and print the average of the numbers
public class bpc5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = 0;
        for (int i = 1; i < 6; i++) {
            System.out.print("Print number " + i + " : ");
            sum += scanner.nextInt();
        }
        System.out.println("Average of the numbers is : " + (sum / 5));
        scanner.close();
    }
}
