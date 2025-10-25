import java.awt.*;
import java.awt.event.*;

class A extends Frame
{
A()
{
Panel panel=new Panel();
panel.setLayout(new FlowLayout());
Button b1=new Button("Click 1");
b1.setBackground(Color.yellow);
Button b2=new Button("Click 2");
b2.setBackground(Color.red);
panel.setBackground(Color.gray);
panel.add(b1);
panel.add(b2);
add(panel);
setSize(500,500);
setVisible(true);
}
}

class B 
{
public static void main(String st[])
{
new A();
}
}
