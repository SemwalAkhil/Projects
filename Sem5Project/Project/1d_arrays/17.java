class Main {
    public static void main(String[] args) {
        int[] arr = {10, 50, 20, 40, 30};

        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i];
            }
        }

        System.out.println("2nd largest element in the array: " + secondLargest);
    }
}
// 2nd largest element in the array: 40
