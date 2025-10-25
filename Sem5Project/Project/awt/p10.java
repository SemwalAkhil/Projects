//10. Create a simple AWT application that displays a Choice with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowChoice extends Frame
{
    FlowChoice()
    {
        setLayout(new FlowLayout());
        
        Choice ch = new Choice();
        ch.add("Red");
        ch.add("Green");
        ch.add("Blue");
        add(ch);
        
        setTitle("FlowLayout Choice");
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
        new FlowChoice();
    }
}