// 5. How to convert String to float

 class StringToFloat {
    public static void main(String[] args) {
        
        String floatStr1 = "123.45";
        try {
            float num1 = Float.parseFloat(floatStr1);
            System.out.println("Converted float: " + num1);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: " + floatStr1);
        }
    }
}
/*
 Output:
Converted float: 123.45
 */