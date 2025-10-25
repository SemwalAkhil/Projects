// 9. Create an applet in Java to draw a oval.

import java.applet.Applet;
import java.awt.Graphics;

public class q9 extends  Applet{
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
    g.drawOval(250,250,100,50);
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

// <applet code="q9.class" width="500" height="500"></applet>

