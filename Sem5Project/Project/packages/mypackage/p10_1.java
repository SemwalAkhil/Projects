// 10.1. Create a package with a public class having public members.

package mypackage;

public class p10_1 {
    public String message = "Public member accessed successfully!";
    
    public void showMessage() {
        System.out.println(message);
    }
}
