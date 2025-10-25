import java.awt.*;
class A {
    public static void main(String[] args) {
        
        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        
        
        String[] fonts = ge.getAvailableFontFamilyNames();

       
        System.out.println("Available Fonts on the System are:");
        for (String font : fonts) {
            System.out.println(font);
        }
    }
}