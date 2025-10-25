class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int n = 1; // number of times to rotate

        System.out.println("Original array:");
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");

        // Right rotate
        for (int i = 0; i < n; i++) {
            int last = arr[arr.length - 1];
            for (int j = arr.length - 1; j > 0; j--) {
                arr[j] = arr[j - 1];
            }
            arr[0] = last;
        }

        System.out.println("\nArray after right rotation:");
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }
}
// Original array:
// 1 2 3 4 5 
// Array after right rotation:
// 5 1 2 3 4
