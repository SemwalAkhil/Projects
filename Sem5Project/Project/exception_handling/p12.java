// 12. Write a Java program to show an example of multiple catch

class twelve {
    public static void main(String[] args) {
        System.out.println("Multiple catch blocks");
        try {
            int[] arr = new int[5];
            arr[2] = 10;

            int result = arr[2] / 0;

            arr[10] = 50;

        } catch (ArithmeticException e) {
            System.out.println("Caught ArithmeticException: " + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Caught ArrayIndexOutOfBoundsException: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Caught general exception: " + e.getMessage());
        }

    }
}
