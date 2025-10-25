//17. Create a simple AWT application that displays a TextArea with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomTextArea extends Frame
{
    CustomTextArea()
    {
        setLayout(null);
        
        TextArea ta = new TextArea("Type here...");
        ta.setBounds(70, 70, 150, 100);
        add(ta);
        
        setTitle("Custom Layout TextArea");
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
        new CustomTextArea();
    }
}