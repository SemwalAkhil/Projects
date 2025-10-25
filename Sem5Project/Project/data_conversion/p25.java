// 25. How to convert Binary to Decimal

class BinaryToDecimal {
    public static void main(String[] args) {
        String binaryString = "1010";  // binary for decimal 10
        int decimalValue = Integer.parseInt(binaryString, 2);

        System.out.println("Binary: " + binaryString);
        System.out.println("Decimal: " + decimalValue);
    }
}
/*Output:
Binary: 1010
Decimal: 10
 */