//9. Create a simple AWT application that displays a Label with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomLabel extends Frame
{
    CustomLabel()
    {
        setLayout(null);
        
        Label lbl = new Label("Hello Custom Layout!");
        lbl.setBounds(80, 100, 150, 30);
        add(lbl);
        
        setTitle("Custom Layout Label");
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
        new CustomLabel();
    }
}