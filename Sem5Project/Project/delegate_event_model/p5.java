          
import java.awt.*;
import java.awt.event.*;

class KeyboardEventExample {
    public static void main(String[] args) {
       
        final Frame frame = new Frame("Keyboard Event Example");
        frame.setSize(900, 500);
        frame.setLayout(new FlowLayout());

     
        final Label label = new Label("Press any key...");
        frame.add(label);

        
        frame.addKeyListener(new KeyAdapter() {
           
            public void keyPressed(KeyEvent e) {
               
                int keyCode = e.getKeyCode();
                char keyChar = e.getKeyChar();
               
                label.setText("Key Pressed: " + keyChar + " (Key Code: " + keyCode + ")");
            }

          
            public void keyReleased(KeyEvent e) {
               
                int keyCode = e.getKeyCode();
                label.setText("Key Released: Key Code: " + keyCode);
            }
        });

        
        frame.addWindowListener(new WindowAdapter() {
          
            public void windowClosing(WindowEvent e) {
                frame.dispose(); 
            }
        });

        
        frame.setVisible(true);
    }
}
 

