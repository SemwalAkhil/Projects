//5. Create a simple AWT application that displays a TextField with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomTextField extends Frame
{
    CustomTextField()
    {
        setLayout(null);
        
        TextField tf = new TextField("Enter text here");
        tf.setBounds(80, 100, 150, 30);
        add(tf);
        
        setTitle("Custom Layout TextField");
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
        new CustomTextField();
    }
}