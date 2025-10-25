// 28. How to convert Decimal to Hex

class Decimal_Hex {
    public static void main(String[] args) {
        int decimalValue = 6719;

        // Convert decimal integer to hex string
        String hexString = Integer.toHexString(decimalValue);

        System.out.println("Decimal: " + decimalValue);
        System.out.println("Hexadecimal: " + hexString);
    }
}
/*Output:
Decimal: 6719
Hexadecimal: 1a3f
 */