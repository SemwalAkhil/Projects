             import java.awt.Frame;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.Label;

public class de2 {
    public static void main(String[] args) {
        Frame frame = new Frame();
        
        Label label1 = new Label("Enter your text:");
        label1.setBounds(20, 50, 100, 30);
        TextArea textArea = new TextArea();
        textArea.setBounds(20, 80, 250, 100);
        
        Label label2 = new Label("Password:");
        label2.setBounds(20, 190, 100, 30);
        
        TextField passwordField = new TextField();
        passwordField.setEchoChar('*'); 
        passwordField.setBounds(20, 220, 250, 30);
        
        frame.add(label1);
        frame.add(textArea);
        frame.add(label2);
        frame.add(passwordField);
        
       
        frame.setSize(400, 300);
        frame.setLayout(null);  
        
        
        frame.setVisible(true);
    }
}
