// 9.1. Create a nested package 'c4.sample' with a public class having protected members.

package c4.sample;

public class p9_1 {
    protected String info = "Accessed protected member from nested package!";
    protected void display() {
        System.out.println(info);
    }
}
