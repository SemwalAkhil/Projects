//4. Create a simple AWT application that displays a TextField with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowTextField extends Frame
{
    FlowTextField()
    {
        setLayout(new FlowLayout());
        
        TextField tf = new TextField(20);
        add(tf);
        
        setTitle("FlowLayout with TextField");
        setSize(300, 150);
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
        new FlowTextField();
    }
}