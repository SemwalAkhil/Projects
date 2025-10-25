import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        int[] arr = {50, 20, 40, 10, 30};

        // Sorting in ascending order
        Arrays.sort(arr);

        System.out.println("Array in ascending order:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
// Array in ascending order:
// 10 20 30 40 50

