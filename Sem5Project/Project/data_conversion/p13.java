// 13. How to convert String to Object

class StringToObject {
    public static void main(String[] args) {
        String str = "Hello, World";

        Object obj = str;

        System.out.println("Object value: " + obj);

        if (obj instanceof String) {
            System.out.println("The object is a String.");
        }
    }
}

/*
Output:
Object value: Hello, World
The object is a String.
 */