import java.awt.*;
import java.awt.event.*;
import java.util.Random;

class DotsDisplay extends Frame implements Runnable {
private final int DOT_COUNT = 100;    
private final int DOT_SIZE = 10;    
private final Random random = new Random();
private Thread thread;
public DotsDisplay() {

setTitle("Dots Display");
setSize(500, 500);
setVisible(true);
setResizable(false);

thread = new Thread(this);
thread.start();
}

@Override
public void paint(Graphics g) {

g.clearRect(0, 0, getWidth(), getHeight());

for (int i = 0; i < DOT_COUNT; i++) {
int x = random.nextInt(getWidth() - DOT_SIZE);
int y = random.nextInt(getHeight() - DOT_SIZE);
g.fillOval(x, y, DOT_SIZE, DOT_SIZE); 
}
}

@Override
public void run() {
while (true) {
repaint(); 
try {
Thread.sleep(100); 
} catch (InterruptedException e) {
e.printStackTrace();
}
}
}

public static void main(String[] args) {
new DotsDisplay();
}
}
