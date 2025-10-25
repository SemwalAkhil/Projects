// 18. How to convert double to int

class DoubleToInt {
    public static void main(String[] args) {
        double doubleValue = 42.99;

        int intValue = (int) doubleValue;

        System.out.println("Double value: " + doubleValue);
        System.out.println("Int value (after casting): " + intValue);
    }
}

/*
Output:
Double value: 42.99
Int value (after casting): 42
 */