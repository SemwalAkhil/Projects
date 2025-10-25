            import java.awt.*;
import java.awt.event.*;

class A {
    public static void main(String[] args) {
        
        Frame frame = new Frame("Keyboard Event Example");
        frame.setSize(400, 200);
        frame.setLayout(new FlowLayout());

        

        
        frame.addMouseListener(new MouseAdapter() {
          
            public void mouseClicked(MouseEvent e) {
                System.out.println("Mouse Clicked at: (" + e.getX() + ", " + e.getY() + ")");
            }

           
            public void mousePressed(MouseEvent e) {
                System.out.println("Mouse Pressed");
            }

          
            public void mouseReleased(MouseEvent e) {
                System.out.println("Mouse Released");
            }
        });

        
        
        frame.setVisible(true);
       
    }
}

output
            Mouse Pressed
            Mouse Released
            Mouse Clicked at: (210, 101)
            Mouse Pressed
            Mouse Released
            Mouse Clicked at: (210, 101)
            Mouse Pressed
            Mouse Released
            Mouse Clicked at: (210, 101)
            Mouse Pressed
            Mouse Released
            Mouse Clicked at: (237, 102)
        