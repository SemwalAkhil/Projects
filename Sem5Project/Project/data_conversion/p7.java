// 7. How to convert String to double

class StringToDouble {
    public static void main(String[] args) {
 
        String doubleStr1 = "456.789";
        try {
            double num1 = Double.parseDouble(doubleStr1);
            System.out.println("Converted double: " + num1);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: " + doubleStr1);
        }

    }
}

/*
Output:
Converted double: 456.789
 */