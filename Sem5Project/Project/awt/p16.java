//16. Create a simple AWT application that displays a TextArea with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowTextArea extends Frame
{
    FlowTextArea()
    {
        setLayout(new FlowLayout());
        
        TextArea ta = new TextArea("Enter your message here...", 5, 20);
        add(ta);
        
        setTitle("FlowLayout TextArea");
        setSize(300, 200);
        setVisible(true);
        
        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }
        });
    }
}

class Main
{
    public static void main(String[] args)
    {
        new FlowTextArea();
    }
}