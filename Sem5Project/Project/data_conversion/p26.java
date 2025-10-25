// 26. How to convert Decimal to Binary

class DecimalToBinary {
    public static void main(String[] args) {
        int decimalValue = 10;

        String binaryString = Integer.toBinaryString(decimalValue);

        System.out.println("Decimal: " + decimalValue);
        System.out.println("Binary: " + binaryString);
    }
}
/*Output:
Decimal: 10
Binary: 1010
 */