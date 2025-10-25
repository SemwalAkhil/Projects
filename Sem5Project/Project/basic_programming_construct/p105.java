import java.util.Scanner;

public class MarksTotalPercentage {
    static int calculateTotal(int[] marks) {
        int total = 0;
        for(int mark : marks) {
            total += mark;
        }
        return total;
    }

    static double calculatePercentage(int total, int maxMarks) {
        return (total * 100.0) / maxMarks;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of subjects: ");
        int n = sc.nextInt();

        int[] marks = new int[n];
        System.out.println("Enter marks:");
        for(int i=0; i<n; i++) {
            marks[i] = sc.nextInt();
        }

        int maxMarks = n * 100; // assuming max marks per subject is 100
        int total = calculateTotal(marks);
        double percentage = calculatePercentage(total, maxMarks);

        System.out.println("Total Marks: " + total);
        System.out.println("Percentage: " + percentage + " %");
        sc.close();
    }
}
output:-
        Enter number of subjects: 3
        Enter marks:
        85
        90
        80
        Total Marks: 255
        Percentage: 85.0 %
        