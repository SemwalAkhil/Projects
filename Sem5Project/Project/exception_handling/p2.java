// 2. Write a Java program to create a method that takes an integer as a parameter and throws an exception if the number is odd.

class MyException extends Exception {
    public MyException(String message) {
        super(message);
    }
}

class Excep {

    public static void checkOdd(int num) throws MyException {
        if (num % 2 != 0) {

            throw new MyException("Number is odd! Please enter an even number.");
        } else {
            System.out.println(num + " is even.");
        }
    }

    public static void main(String[] args) {
        try {

            if (args.length == 0) {
                throw new ArrayIndexOutOfBoundsException();
            }

            int x = Integer.parseInt(args[0]);
            checkOdd(x);

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("No input found: Please enter a number as an argument.");
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: Please enter a valid integer.");
        } catch (MyException e) {
            System.out.println("Exception : " + e.getMessage());
        }
    }
}
