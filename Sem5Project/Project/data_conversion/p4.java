// 4. How to convert long to String

class LongToString {
    public static void main(String[] args) {
        long number = 9876543210L;

        String str1 = String.valueOf(number);
        System.out.println("Using String.valueOf(): " + str1);

        String str2 = Long.toString(number);
        System.out.println("Using Long.toString(): " + str2);

        String str3 = number + "";
        System.out.println("Using concatenation: " + str3);
    }
}

/*
Output:
Using String.valueOf(): 9876543210
Using Long.toString(): 9876543210
Using concatenation: 9876543210
 */