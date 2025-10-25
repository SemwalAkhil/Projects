// 13. Write a Java program to show an example of nested try block.

class thirteen {
    public static void main(String[] args) {
        try {

            int[] arr = new int[5];
            arr[2] = 10;
            try {
                int result = arr[2] / 0;
                System.out.println("Result: " + result);
            } catch (ArithmeticException e) {
                System.out.println("Inner catch: ArithmeticException caught : " + e.getMessage());
            }

            arr[10] = 50;

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Outer catch: ArrayIndexOutOfBoundsException caught : " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Outer catch: General Exception caught : " + e.getMessage());
        }

    }
}
