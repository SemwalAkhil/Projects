//3. Create a simple AWT application that displays multiple buttons with BorderLayout manager.

import java.awt.*;
import java.awt.event.*;

class BorderButtons extends Frame
{
    BorderButtons()
    {
        setLayout(new BorderLayout());
        
        add(new Button("North"), BorderLayout.NORTH);
        add(new Button("South"), BorderLayout.SOUTH);
        add(new Button("East"), BorderLayout.EAST);
        add(new Button("West"), BorderLayout.WEST);
        add(new Button("Center"), BorderLayout.CENTER);
        
        setTitle("BorderLayout Example");
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
        new BorderButtons();
    }
}