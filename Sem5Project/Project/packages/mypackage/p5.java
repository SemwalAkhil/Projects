// 5. Access multiple default classes inside the same package.

package mypackage;

class p5 {
    public static void main(String args[]) {
        p5_1 obj1 = new p5_1();
        p5_2 obj2 = new p5_2();

        obj1.displayMessage();
        obj2.showMessage();
    }
}
