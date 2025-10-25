//6. Create a simple AWT application that displays a Checkbox with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowCheckbox extends Frame
{
    FlowCheckbox()
    {
        setLayout(new FlowLayout());
        
        Checkbox cb = new Checkbox("I Agree");
        add(cb);
        
        setTitle("FlowLayout Checkbox");
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
        new FlowCheckbox();
    }
}