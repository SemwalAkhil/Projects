import java.awt.*;
import java.awt.event.*;

class A extends Frame
{
TextField f1;
A()
{
f1=new TextField();
setLayout(null);
f1.setBounds(30,30,100,20);
add(f1);
f1.addKeyListener(new KeyAdapter(){
public void keyTyped(KeyEvent e)
{
char c=e.getKeyChar();
if(!isValidEmailCharacter(c) && c!=KeyEvent.VK_BACK_SPACE)
{
e.consume();
}
}
private boolean isValidEmailCharacter(char c)
{
return Character.isLetterOrDigit(c) || c=='@' ||
 c=='#' || c=='!' || c=='$' || c=='?' || c=='&' ||
  c=='^' || c=='%' ;
}
});

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
