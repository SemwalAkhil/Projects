//18. Create a simple AWT application design a calculator that displays buttons, TextField with GridLayout manager.

import java.awt.*;
import java.awt.event.*;

class CalculatorGrid extends Frame
{
    CalculatorGrid()
    {
        setLayout(new BorderLayout());
        
        TextField tf = new TextField();
        add(tf, BorderLayout.NORTH);
        
        Panel p = new Panel();
        p.setLayout(new GridLayout(4, 4, 5, 5));
        
        String btns[] = {"7","8","9","/",
                         "4","5","6","*",
                         "1","2","3","-",
                         "0",".","=","+"};
                         
        for(String s : btns)
            p.add(new Button(s));
        
        add(p, BorderLayout.CENTER);
        
        setTitle("GridLayout Calculator");
        setSize(300, 300);
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
        new CalculatorGrid();
    }
}