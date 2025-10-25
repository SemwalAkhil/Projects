// 20. How to convert int to char

class IntToChar {
    public static void main(String[] args) {
        int intValue = 65;  // Unicode for 'A'

        char ch = (char) intValue;

        System.out.println("Int value: " + intValue);
        System.out.println("Char value: " + ch);
    }
}

/*
Output:
Int value: 65
Char value: A
 */