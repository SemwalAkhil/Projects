// 4. Write a Java program that performs matrix multiplication using multiple threads.

class MatrixMultiplyThread extends Thread {
    private int[][] A, B, C;
    private int row;

    MatrixMultiplyThread(int[][] A, int[][] B, int[][] C, int row) {
        this.A = A;
        this.B = B;
        this.C = C;
        this.row = row;
    }

    public void run() {
        for (int j = 0; j < B[0].length; j++) {
            C[row][j] = 0;
            for (int k = 0; k < B.length; k++) {
                C[row][j] += A[row][k] * B[k][j];
            }
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int[][] A = {
            {1, 2, 3},
            {4, 5, 6}
        };
        int[][] B = {
            {7, 8},
            {9, 10},
            {11, 12}
        };
        int[][] C = new int[A.length][B[0].length];

        Thread[] threads = new Thread[A.length];

        for (int i = 0; i < A.length; i++) {
            threads[i] = new MatrixMultiplyThread(A, B, C, i);
            threads[i].start();
        }

        for (int i = 0; i < A.length; i++) {
            threads[i].join();
        }

        System.out.println("Resultant Matrix:");
        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < C[0].length; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.println();
        }
    }
}

/*
Output:
Resultant Matrix:
58 64 
139 154 
*/
