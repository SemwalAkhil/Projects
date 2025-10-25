// Create an applet in Java to set font.
import java.applet.*;
import java.awt.*;

/*
<applet code="SetFontApplet" width="400" height="300"></applet>
*/

public class SetFontApplet extends Applet {
    Font f1, f2, f3;

    public void init() {
        f1 = new Font("Serif", Font.PLAIN, 20);     
        f2 = new Font("SansSerif", Font.BOLD, 24);   
        f3 = new Font("Monospaced", Font.ITALIC, 22); 
    }

    public void paint(Graphics g) {
        g.setFont(f1);
        g.drawString("This is Serif - Plain", 50, 80);

        g.setFont(f2);
        g.drawString("This is SansSerif - Bold", 50, 130);

        g.setFont(f3);
        g.drawString("This is Monospaced - Italic", 50, 180);
    }
}
