// 14. How to convert Object to String

class ObjectToString {
    public static void main(String[] args) {
      
        Object obj = "Hello, Java";

        String str1 = String.valueOf(obj);
        System.out.println("Using String.valueOf(): " + str1);

        String str2 = obj.toString();
        System.out.println("Using toString(): " + str2);
    }
}

/*
Output:
Using String.valueOf(): Hello, Java
Using toString(): Hello, Java
 */