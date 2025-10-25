import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Color;

public class RoundedRectangleApplet extends Applet {

    // Called when the applet is first loaded
    public void init() {
        setBackground(Color.white); // Set background color
    }

    // Called to paint the applet content
    public void paint(Graphics g) {
        g.setColor(Color.blue); // Set color for the rectangle

        // Draw a rounded rectangle
        // Parameters: x, y, width, height, arcWidth, arcHeight
        g.drawRoundRect(50, 50, 200, 100, 30, 30);

        // Optional: fill the rounded rectangle
        g.setColor(Color.cyan);
        g.fillRoundRect(50, 200, 200, 100, 50, 50);
    }
}
