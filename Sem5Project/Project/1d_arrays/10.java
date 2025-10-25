class Main {
    public static void main(String[] args) {
        int[] arr = {10, 25, 5, 60, 45};

        int smallest = arr[0]; // assume first element is smallest

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }

        System.out.println("Smallest element in the array: " + smallest);
    }
}
// Smallest element in the array: 5

