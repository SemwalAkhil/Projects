//8. Create a simple AWT application that displays a Label with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowLabel extends Frame
{
    FlowLabel()
    {
        setLayout(new FlowLayout());
        
        Label lbl = new Label("Welcome to AWT!");
        add(lbl);
        
        setTitle("FlowLayout Label");
        setSize(250, 150);
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
        new FlowLabel();
    }
}