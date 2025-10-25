// 9. Access the protected members of a public class from a nested package.

import c4.sample.*;

class p9 extends p9_1 {
    public static void main(String args[]) {
        p9 obj = new p9();
        obj.display();
    }
}
