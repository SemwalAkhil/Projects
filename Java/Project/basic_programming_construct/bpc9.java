// 9. Write a Java program to check whether Java is installed on your computer or not
public class bpc9 {
    public static void main(String[] args) {
        String version = System.getProperty("java.version");
        if (version != null) {
            System.out.println("Java is installed version: " + version);
        } else {
            System.out.println("Java not found");
        }
    }
}
