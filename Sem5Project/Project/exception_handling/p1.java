// 1. Write a Java program that throws an exception and catch it using a try-catch block.

class a {
    public static void main(String[] args) {

        try {

            String a = args[0];
            System.out.println(a);
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        }

    }
}

/*
 * Output
 * 
 * 
 * 
 */
