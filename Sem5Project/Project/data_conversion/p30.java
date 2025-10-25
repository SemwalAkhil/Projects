// 30. How to convert Decimal to Octal

class Dec_Oct {
    public static void main(String[] args) {
        int decimalValue = 15;

        String octalString = Integer.toOctalString(decimalValue);

        System.out.println("Decimal: " + decimalValue);
        System.out.println("Octal: " + octalString);
    }
}

/*Output:
Decimal: 15
Octal: 17
 */