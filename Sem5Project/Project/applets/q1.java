// 1. Create an applet showing the string "Hello World" which is embedded in the HTML page.

import java.applet.Applet;
import java.awt.Graphics;

public class q1 extends  Applet{
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
    g.drawString("hello world",100,150);
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
