import java.awt.*;
import java.awt.event.*;

class A {
    public static void main(String[] args) {
        final Frame frame = new Frame("Close Frame Example"); 
        frame.setSize(300, 200);
        frame.setLayout(new FlowLayout());

        Label label = new Label("Click the close button to close the frame.");
        frame.add(label);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                frame.dispose(); 
            }
        });

        frame.setVisible(true); 
    }
}