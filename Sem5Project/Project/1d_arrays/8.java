class Main {
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50, 60};

        System.out.println("Elements of array present on odd positions:");

        for (int i = 0; i < arr.length; i += 2) {  // index starts from 0, so 0 means 1st position
            System.out.println(arr[i]);
        }
    }
}
// Elements of array present on odd positions:
// 10
// 30
// 50

