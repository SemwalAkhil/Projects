import java.util.Scanner;

public class TransposeMatrix {
    static void transpose(int[][] matrix, int[][] transpose, int rows, int cols) {
        for(int i=0; i<rows; i++) {
            for(int j=0; jols; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
    }

    static void printMatrix(int[][] mat, int rows, int cols) {
        for(int i=0; i<rows; i++) {
            for(int j=0; jols; j++) {
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter rows: ");
        int rows = sc.nextInt();
        System.out.print("Enter cols: ");
        int cols = sc.nextInt();

        int[][] matrix = new int[rows][cols];
        int[][] transpose = new int[cols][rows];

        System.out.println("Enter matrix elements:");
        for(int i=0; i<rows; i++) {
            for(int j=0; jols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        transpose(matrix, transpose, rows, cols);

        System.out.println("Transpose of matrix:");
        printMatrix(transpose, cols, rows);

        sc.close();
    }
}
output:-
        Enter rows: 2
        Enter cols: 3
        Enter matrix elements:
        1 2 3
        4 5 6
        Transpose of matrix:
        1 4 
        2 5 
        3 6 
        