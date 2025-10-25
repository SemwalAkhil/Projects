class Main {
    public static void main(String[] args) {
        int[] arr = {10, 50, 20, 40, 30};

        // Sorting array in descending order using simple bubble sort
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        // 3rd largest element is at index 2 after sorting
        System.out.println("3rd largest element in the array: " + arr[2]);
    }
}
// 3rd largest element in the array: 30
