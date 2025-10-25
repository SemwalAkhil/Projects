class Main {
    public static void main(String[] args) {
        String str = "Java is easy to learn";

        // Split string into words using space as delimiter
        String[] substrings = str.split(" ");

        // Print all substrings using regular for loop
        for (int i = 0; i < substrings.length; i++) {
            System.out.println(substrings[i]);
        }
    }
}
