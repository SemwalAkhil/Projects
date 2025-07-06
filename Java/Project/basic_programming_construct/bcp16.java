// 16. Write a Java program to print the odd numbers from 1 to 20
public class bcp16 {
    public static void main(String[] args) {
        for (int i = 1; i <= 20; i++) {
            if (i % 2 != 0) {
                System.out.print(i + " ");
            }
        }
    }
}
