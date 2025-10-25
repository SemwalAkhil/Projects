// 5. Create a Java program to access a package with multiple default classes.


import mypackage.*;

// Use same class name as script name
class p5 {
    public static void main(String args[]) {
        // Create objects of both default classes
        FirstClass obj1 = new FirstClass();
        SecondClass obj2 = new SecondClass();

        // Call their methods
        obj1.displayMessage();
        obj2.showMessage();
    }
}
