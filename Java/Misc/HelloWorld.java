import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.Button;




/*
<applet code="HelloWorld.class" width="300" height="400">
</applet>
*/
public class HelloWorld extends Applet {
    Button b=new Button("cancel");
public void init()
{
add(b);
System.out.println("init");
}
public void start()
{

System.out.println("start");
}
public void stop()
{

System.out.println("stop");
}
public void destroy()
{
System.out.println("destroy");
}
public void paint(Graphics g)
    {
g.setColor(Color.red);
        g.drawString("Hello World", 120, 200);
System.out.println("paint");

    }
}