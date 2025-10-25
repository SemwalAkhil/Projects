// 27. How to convert Hex to Decimal

class HexToDecimal {
    public static void main(String[] args) {
        String hexString = "1A3F";  // hex for decimal 6719

        // Convert hex string to decimal integer
        int decimalValue = Integer.parseInt(hexString, 16);

        System.out.println("Hexadecimal: " + hexString);
        System.out.println("Decimal: " + decimalValue);
    }
}
/*Output:
Hexadecimal: 1A3F
Decimal: 6719
 */