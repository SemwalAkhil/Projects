 import java.awt.Frame;
import java.awt.Label;

public class de1 {
    public static void main(String[] args) {
        Frame frame = new Frame("AWT Label ");
        
       
        Label label = new Label("Hello, welcome to the world of java!");
        
       
        label.setBounds(50, 50, 300, 30);
    
        frame.add(label);
        
        frame.setSize(400, 400);
        frame.setLayout(null);  
        
        
        frame.setVisible(true);
    }
}
