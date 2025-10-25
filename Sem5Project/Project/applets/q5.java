// 5. Create an applet in Java to draw a rectangle.

import java.applet.Applet;
import java.awt.Graphics;

public class q5 extends  Applet{
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
    g.drawRect(100,200,100,50);
    g.fillRect(100,200,100,50);
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

// <applet code="q5.class" width="500" height="500"></applet>