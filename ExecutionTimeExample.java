public class ExecutionTimeExample {
    public static void main(String[] args) {
        // Start measuring time
        long startTime = System.nanoTime();

        // Code block whose execution time you want to measure
        for (int i = 0; i < 100000000; i++)
            ; // Example loop

        // Stop measuring time
        long endTime = System.nanoTime();

        // Calculate the time taken in seconds
        double timeTaken = (endTime - startTime) / 1_000_000_000.0;

        System.out.printf("JAVA Execution Time: %.6f seconds%n", timeTaken);
    }
}
