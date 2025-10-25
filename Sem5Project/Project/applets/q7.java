// <!-- 7. Create an applet in Java to draw a 4 concentric circles. -->

import java.applet.Applet;
import java.awt.Graphics;

public class q7 extends  Applet{
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
    int x = 150;
    int y = 150;
    g.drawOval(x - 20, y - 20, 40, 40);
    g.drawOval(x - 40, y - 40, 80, 80);
    g.drawOval(x - 60, y - 60, 120, 120);
    g.drawOval(x - 80, y - 80, 160, 160);
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

// <applet code="q7.class" width="500" height="500"></applet>