// 3. How to convert String to long

class StringToLong {
    public static void main(String[] args) {
 
        String longStr1 = "1234567890";
        try {
            long num1 = Long.parseLong(longStr1);
            System.out.println("Converted long: " + num1);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: " + longStr1);
        }
    }
}
/*
Output:
 Converted long: 1234567890
 */