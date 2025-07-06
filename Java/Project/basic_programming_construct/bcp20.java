// 20. Write a Java program to compute the sum of the first 100 prime numbers
public class bcp20 {
    public static void main(String[] args) {
        int[] primeArr = new int[100];
        primeArr[0] = 2;
        int current = 3, sum = 2;
        boolean prime = true;
        int count = 1;
        // System.out.println(count + " > " + current);
        while (count < 100) {
            for (int j = 0; j < count; j++) {
                if (primeArr[j] != 0 && current % primeArr[j] == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) {
                primeArr[count++] = current;
                sum += current;
                // System.out.println(count + " > " + current);
            }
            current++;
            prime = true;
        }
        System.out.println("Sum of first 100 prime : %d".formatted(sum));
    }
}
