//15. Create a simple AWT application that displays a List with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomList extends Frame
{
    CustomList()
    {
        setLayout(null);
        
        List list = new List(4);
        list.add("Apple");
        list.add("Banana");
        list.add("Mango");
        list.add("Orange");
        list.setBounds(100, 80, 100, 80);
        add(list);
        
        setTitle("Custom Layout List");
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
        new CustomList();
    }
}