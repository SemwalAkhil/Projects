import java.util.*;

// 41. Java program to calculate average marks
public class bcp41 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of subjects : ");
        int x = scanner.nextInt();
        double marks = 0;
        double total = 0;
        double sum = 0;
        for (int i = 0; i < x; i++) {
            System.out.print("Enter total marks for subject %d : ".formatted(i + 1));
            total = scanner.nextDouble();
            marks = total + 1;
            while (marks > total || marks < 0) {
                System.out.print("Enter marks scored in subject %d (0 - %.2f) : ".formatted(i + 1, total));
                marks = scanner.nextDouble();
                if (marks > total || marks < 0) {
                    System.out.println("Enter valid marks in range (0 - %.2f)".formatted(total));
                }
            }
            sum += marks;
        }
        System.out.println("Average Marks : %.2f".formatted((double) sum / x));
        scanner.close();
    }
}
