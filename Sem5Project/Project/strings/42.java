class Main {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "World";

        System.out.println("Before swap: str1 = " + str1 + ", str2 = " + str2);

        // Swap using a temporary variable
        String temp = str1;
        str1 = str2;
        str2 = temp;

        System.out.println("After swap: str1 = " + str1 + ", str2 = " + str2);
    }
}

