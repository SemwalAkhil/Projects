 class Main {
    public static void main(String[] args) {
        String original = "Hello";

        System.out.println("Original string: " + original);

        // Try to change the string
        String changed = original.concat(" World"); // concat creates a new string

        System.out.println("After concat, original: " + original);
        System.out.println("After concat, changed: " + changed);

        // Check if both refer to same object
        if (original == changed) {
            System.out.println("Same object");
        } else {
            System.out.println("Different objects (String is immutable)");
        }
    }
}
