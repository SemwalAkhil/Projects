//12. Create a simple AWT application that displays a CheckboxGroup with FlowLayout manager.

import java.awt.*;
import java.awt.event.*;

class FlowCheckboxGroup extends Frame
{
    FlowCheckboxGroup()
    {
        setLayout(new FlowLayout());
        
        CheckboxGroup gender = new CheckboxGroup();
        Checkbox male = new Checkbox("Male", gender, false);
        Checkbox female = new Checkbox("Female", gender, false);
        
        add(male);
        add(female);
        
        setTitle("FlowLayout CheckboxGroup");
        setSize(300, 150);
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
        new FlowCheckboxGroup();
    }
}