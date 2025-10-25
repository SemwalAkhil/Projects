// 6.2. Create a Java program to access a package with 4 public classes and call their methods.

import mypackage.*;

class p6 {
    public static void main(String args[]) {
        p6_1 obj1 = new p6_1();
        p6_2 obj2 = new p6_2();
        p6_3 obj3 = new p6_3();
        p6_4 obj4 = new p6_4();

        obj1.show();
        obj2.display();
        obj3.print();
        obj4.message();
    }
}
