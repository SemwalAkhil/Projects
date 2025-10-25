 class Main {
    public static void main(String[] args) {
        String str = "Java Is FuN";
        String result = "";

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if (Character.isLowerCase(ch)) {
                result += Character.toUpperCase(ch);
            } else if (Character.isUpperCase(ch)) {
                result += Character.toLowerCase(ch);
            } else {
                result += ch; // for spaces or other characters
            }
        }

        System.out.println("After case change: " + result);
    }
}
