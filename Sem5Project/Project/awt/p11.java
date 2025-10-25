//11. Create a simple AWT application that displays a Choice with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomChoice extends Frame
{
    CustomChoice()
    {
        setLayout(null);
        
        Choice ch = new Choice();
        ch.add("Apple");
        ch.add("Banana");
        ch.add("Mango");
        ch.setBounds(100, 100, 100, 30);
        add(ch);
        
        setTitle("Custom Layout Choice");
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
        new CustomChoice();
    }
}