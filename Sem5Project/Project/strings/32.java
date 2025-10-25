 class Main {
    public static void main(String[] args) {
        String str1 = "Hello World";
        String str2 = "Beautiful ";
        int position = 6; // position after "Hello "

        String newString = str1.substring(0, position) + str2 + str1.substring(position);

        System.out.println("After insertion: " + newString);
    }
}
