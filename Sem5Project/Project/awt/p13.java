//13. Create a simple AWT application that displays a CheckboxGroup with Custom Layout.

import java.awt.*;
import java.awt.event.*;

class CustomCheckboxGroup extends Frame
{
    CustomCheckboxGroup()
    {
        setLayout(null);
        
        CheckboxGroup cg = new CheckboxGroup();
        Checkbox opt1 = new Checkbox("Yes", cg, false);
        Checkbox opt2 = new Checkbox("No", cg, false);
        
        opt1.setBounds(80, 100, 80, 30);
        opt2.setBounds(80, 140, 80, 30);
        add(opt1);
        add(opt2);
        
        setTitle("Custom Layout CheckboxGroup");
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
        new CustomCheckboxGroup();
    }
}