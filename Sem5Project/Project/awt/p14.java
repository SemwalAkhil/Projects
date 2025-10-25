//14. Create a simple AWT application that displays a List with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowList extends Frame
{
    FlowList()
    {
        setLayout(new FlowLayout());
        
        List list = new List(3);
        list.add("C");
        list.add("C++");
        list.add("Java");
        list.add("Python");
        add(list);
        
        setTitle("FlowLayout List");
        setSize(250, 200);
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
        new FlowList();
    }
}