class Main {
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4, 5};   // Original array
        int[] arr2 = new int[arr1.length]; // New array with same size

        // Copying elements
        for (int i = 0; i < arr1.length; i++) {
            arr2[i] = arr1[i];
        }

        // Display copied array
        System.out.println("Elements of new array: ");
        for (int i = 0; i < arr2.length; i++) {
            System.out.print(arr2[i] + " ");
        }
    }
}
// output Elements of new array: 1 2 3 4 5