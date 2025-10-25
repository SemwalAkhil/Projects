// 15. Java Program to Draw a Smiling Face using Graphics Class Methods

import java.applet.Applet;
import java.awt.Graphics;

public class q15 extends Applet{
    public void init(){
    System.out.println("init function");
  }
  public void start()
  {
     System.out.println("start function");
  }
  public void paint(Graphics g)
  {
    int x = 200;
    int y = 200;

    g.setColor(java.awt.Color.red);
    g.drawOval(x - 50, y - 50, 100, 100);
    g.drawOval(x - 25, y - 25, 10, 10);
    g.drawOval(x + 15, y - 25, 10, 10);
    g.drawLine(x, y - 10, x, y + 15);
    g.drawArc(x - 25, y + 10, 50, 20, 0, -180);
  }
  public void stop()
  {
     System.out.println("stop function");
  }
  public void destroy()
  {
     System.out.println("destroy function");
  }
}

// <applet code="q15.class" width="500" height="500"></applet>