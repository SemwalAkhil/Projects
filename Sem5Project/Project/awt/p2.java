//2. Create a simple AWT application that displays a button with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomButton extends Frame
{
    CustomButton()
    {
        setLayout(null); // Custom layout (no layout manager)
        
        Button b = new Button("Click Me");
        b.setBounds(100, 100, 100, 40); // x, y, width, height
        add(b);
        
        setTitle("Custom Layout Example");
        setSize(300, 250);
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
        new CustomButton();
    }
}