// 4. Create an applet in Java to draw a polygon.

import java.applet.Applet;
import java.awt.Graphics;

public class q4 extends  Applet{
   public void init(){
    System.out.println("init function");
  }
  public void start()
  {
     System.out.println("start function");
  }
  public void paint(Graphics g)
  {
    int x[]={10,30,40,50,110,140};
    int y[]={140,110,50,40,30,10};

    int NumberOfPoints=6;

    g.drawPolygon(x,y,NumberOfPoints);
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

// <applet code="q4.class" width="500" height="500"></applet>