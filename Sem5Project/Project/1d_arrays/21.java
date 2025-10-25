class Main {
    public static void main(String[] args) {
        int[] arr = {10, 20, 20, 30, 10, 40, 50, 30};
        int n = arr.length;

        // Using a temporary array to store unique elements
        int[] temp = new int[n];
        int j = 0;

        for (int i = 0; i < n; i++) {
            boolean isDuplicate = false;
            for (int k = 0; k < j; k++) {
                if (arr[i] == temp[k]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                temp[j] = arr[i];
                j++;
            }
        }

        System.out.println("Array after removing duplicates:");
        for (int i = 0; i < j; i++) {
            System.out.print(temp[i] + " ");
        }
    }
}
// Array after removing duplicates:
// 10 20 30 40 50
