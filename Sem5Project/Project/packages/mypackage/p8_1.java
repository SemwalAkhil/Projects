// 8.1. Create a package with a public class having protected members.

package mypackage;

public class p8_1 {
    protected String message = "Protected member accessed successfully!";
    protected void showMessage() {
        System.out.println(message);
    }
}
