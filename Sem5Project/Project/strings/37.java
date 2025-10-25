 class Main {
    public static void main(String[] args) {
        String str = "Java is easy to learn";

        // remove all white spaces
        String result = str.replaceAll("\\s", "");

        System.out.println("String after removing spaces: " + result);
    }
}