// 22. How to convert boolean to String

class BooleanToString {
    public static void main(String[] args) {
        boolean boolValue = true;

        String str1 = String.valueOf(boolValue);
        System.out.println("Using String.valueOf(): " + str1);

        String str2 = Boolean.toString(boolValue);
        System.out.println("Using Boolean.toString(): " + str2);

        String str3 = boolValue + "";
        System.out.println("Using concatenation: " + str3);
    }
}

/*Output:
Using String.valueOf(): true
Using Boolean.toString(): true
Using concatenation: true
 */