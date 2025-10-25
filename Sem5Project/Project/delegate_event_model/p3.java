 import java.awt.*;
import java.awt.event.*;
import java.io.*;

class A extends Frame implements ActionListener {
Image img;

A() {
Button button = new Button("Click Me");

setLayout(null);
button.setBounds(50, 50, 100, 30);
add(button);
button.addActionListener(this);

setSize(500, 500);
setVisible(true);
}

public void actionPerformed(ActionEvent e) {
img = Toolkit.getDefaultToolkit().getImage("C:\\Users
\\vikram\\OneDrive\\Pictures\\New folder\\favicon.ico.jpg");
repaint(); 
}

public void paint(Graphics g) {
if (img != null) {
g.drawImage(img, 50, 100,200,200, this); 
}
}
}

class B
{
public static void main(String st[])
{
new A();
}
}