//1. Create a simple AWT application that displays a button with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowButton extends Frame
{
    FlowButton()
    {
        // Set layout to FlowLayout
        setLayout(new FlowLayout());
        
        // Create a Button
        Button b = new Button("Click Me");
        
        // Add button to frame
        add(b);
        
        // Set frame properties
        setTitle("FlowLayout Example");
        setSize(300, 200);
        setVisible(true);
        
        // Add window closing functionality
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
    public static void main(String st[])
    {
        // Create object of FlowButton class
        new FlowButton();
    }
}