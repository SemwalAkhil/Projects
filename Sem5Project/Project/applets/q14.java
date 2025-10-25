// 14. Create an applet to display a digital clock.
import java.applet.*;
import java.awt.*;
import java.util.*;

/*
<applet code="DigitalClock" width="300" height="150"></applet>
*/

public class DigitalClock extends Applet implements Runnable {
    Thread t = null;
    boolean stopFlag;
    String timeString = "";

    public void start() {
        t = new Thread(this);
        stopFlag = false;
        t.start();
    }

    public void run() {
        try {
            while (!stopFlag) {
                Calendar cal = Calendar.getInstance();
                int hour = cal.get(Calendar.HOUR);
                int minute = cal.get(Calendar.MINUTE);
                int second = cal.get(Calendar.SECOND);
                int am_pm = cal.get(Calendar.AM_PM);

                String ampm = (am_pm == Calendar.AM) ? "AM" : "PM";
                timeString = String.format("%02d:%02d:%02d %s", hour == 0 ? 12 : hour, minute, second, ampm);

                repaint();
                Thread.sleep(1000); 
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public void paint(Graphics g) {
        g.setColor(Color.black);
        g.fillRect(0, 0, 300, 150);

        g.setColor(Color.green);
        g.setFont(new Font("Digital-7 Mono", Font.BOLD, 32));
        g.drawString(timeString, 70, 80);
    }

    public void stop() {
        stopFlag = true;
        t = null;
    }
}
