// 10. Access the public members of a public class from another class.

import mypackage.*;

class p10 {
    public static void main(String args[]) {
        p10_1 obj = new p10_1();
        obj.showMessage();
    }
}
