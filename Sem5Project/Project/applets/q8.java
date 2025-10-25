// 8. Create an applet in Java to draw a line.

import java.applet.Applet;
import java.awt.Graphics;

public class q8 extends  Applet{
   public void init(){
    System.out.println("init function");
  }
  public void start()
  {
     System.out.println("start function");
  }
  public void paint(Graphics g)
  {
    g.setColor(java.awt.Color.red);
    g.drawLine(50,150,250,150);
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

// <applet code="q8.class" width="500" height="500"></applet>