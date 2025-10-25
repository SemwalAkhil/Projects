class Main {
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50, 60};

        System.out.println("Elements of array present on even positions:");

        for (int i = 1; i < arr.length; i += 2) {  // index starts from 0, so 1 means 2nd position
            System.out.println(arr[i]);
        }
    }
}
// Elements of array present on even positions:
// 20
// 40
// 60
