import java.util.Scanner;

public class MatrixAddition {
    // Function to add two matrices
    static void addMatrices(int[][] m1, int[][] m2, int[][] result, int rows, int cols) {
        for(int i=0;i<rows;i++) {
            for(int j=0;jols;j++) {
                result[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }

    // Function to display matrix
    static void displayMatrix(int[][] matrix, int rows, int cols) {
        System.out.println("Result matrix:");
        for(int i=0;i<rows;i++) {
            for(int j=0;jols;j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int r = sc.nextInt();
        System.out.print("Enter number of columns: ");
        int c = sc.nextInt();

        int[][] matrix1 = new int[r][c];
        int[][] matrix2 = new int[r][c];
        int[][] sum = new int[r][c];

        System.out.println("Enter first matrix elements:");
        for(int i=0;i<r;i++) {
            for(int j=0;j;j++) {
                matrix1[i][j] = sc.nextInt();
            }
        }

        System.out.println("Enter second matrix elements:");
        for(int i=0;i<r;i++) {
            for(int j=0;j;j++) {
                matrix2[i][j] = sc.nextInt();
            }
        }

        addMatrices(matrix1, matrix2, sum, r, c);
        displayMatrix(sum, r, c);
        sc.close();
    }
}
output:-
         Enter number of rows: 2
         Enter number of columns: 2
         Enter first matrix elements:
         1 2
         3 4
         Enter second matrix elements:
         5 6
         7 8
         Result matrix:
         6 8
         10 12
