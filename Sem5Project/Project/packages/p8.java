// 8. Access the protected members of a public class from another class.

import mypackage.*;

class p8 extends p8_1 {
    public static void main(String args[]) {
        p8 obj = new p8();
        obj.showMessage();
    }
}