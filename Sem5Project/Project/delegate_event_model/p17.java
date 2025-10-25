 import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;

public class del17 extends Applet
{
Button b1;
public void init()
{
b1=new Button("Click me");
b1.setBounds(50,50,100,40);
add(b1);
b1.addActionListener(new ActionListener(){
public void actionPerformed(ActionEvent e)
{
setBackground(Color.yellow);
}
});
}
}
