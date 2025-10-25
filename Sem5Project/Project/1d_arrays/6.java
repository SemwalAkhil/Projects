class Main {
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};

        System.out.println("Array elements in reverse order:");
        for (int i = arr.length - 1; i >= 0; i--) {
            System.out.println(arr[i]);
        }
    }
}
// Array elements in reverse order:
// 50
// 40
// 30
// 20
// 10
