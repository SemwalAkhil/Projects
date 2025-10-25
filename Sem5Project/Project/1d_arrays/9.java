class Main {
    public static void main(String[] args) {
        int[] arr = {10, 25, 5, 60, 45};

        int largest = arr[0]; // assume first element is largest

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }

        System.out.println("Largest element in the array: " + largest);
    }
}
// Largest element in the array: 60

