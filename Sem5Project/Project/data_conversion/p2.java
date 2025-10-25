// 2. How to convert int to String

class IntToString {
    public static void main(String[] args) {
        int number = 123;

        String str1 = String.valueOf(number);
        System.out.println("Using String.valueOf(): " + str1);

        String str2 = Integer.toString(number);
        System.out.println("Using Integer.toString(): " + str2);

        String str3 = number + "";
        System.out.println("Using concatenation: " + str3);
    }
}
/*
Output
Using String.valueOf(): 123
Using Integer.toString(): 123
Using concatenation: 123
*/