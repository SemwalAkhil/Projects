//7. Create a simple AWT application that displays a Checkbox with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomCheckbox extends Frame
{
    CustomCheckbox()
    {
        setLayout(null);
        
        Checkbox cb = new Checkbox("Accept Terms");
        cb.setBounds(80, 100, 150, 30);
        add(cb);
        
        setTitle("Custom Layout Checkbox");
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
        new CustomCheckbox();
    }
}