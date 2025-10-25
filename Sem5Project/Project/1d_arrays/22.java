class Main {
    public static void main(String[] args) {
        int[] arr = {10, 25, 30, 45, 50, 55};

        System.out.println("Even numbers in the array:");
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 0) {
                System.out.print(arr[i] + " ");
            }
        }

        System.out.println("\nOdd numbers in the array:");
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 != 0) {
                System.out.print(arr[i] + " ");
            }
        }
    }
}
// Even numbers in the array:
// 10 30 50 
// Odd numbers in the array:
// 25 45 55

