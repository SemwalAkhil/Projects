// 29. How to convert Octal to Decimal

class Octal_Decimal {
    public static void main(String[] args) {
        String octalString = "17";  // octal for decimal 15

        int decimalValue = Integer.parseInt(octalString, 8);

        System.out.println("Octal: " + octalString);
        System.out.println("Decimal: " + decimalValue);
    }
}
/*Output:
Octal: 17
Decimal: 15
 */