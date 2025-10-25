
class Main {
    public static void main(String[] args) {
        String str = "Java is easy to learn";
        char replaceWith = '-'; // character to replace spaces

        // Replace all spaces with the specified character
        String result = str.replace(' ', replaceWith);

        System.out.println("After replacing spaces: " + result);
    }
}
