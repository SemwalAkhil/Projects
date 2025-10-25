// 1. How to convert String to int

class StringToInt {
    public static void main(String[] args) {
        
        String numberStr1 = "123";
        try {
            int number1 = Integer.parseInt(numberStr1);
            System.out.println("Converted number: " + number1);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: " + numberStr1);
        }
    }
}

/*
Output:
Converted number: 123
 */