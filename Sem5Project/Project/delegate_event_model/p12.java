import java.awt.*;
import java.awt.event.*;

class  A{
  A() {
       
        Frame mainFrame = new Frame("Main Frame");
        mainFrame.setSize(300, 200);
        mainFrame.setLayout(new FlowLayout());

       
        Button openNewFrameButton = new Button("Open New Frame");

       
        mainFrame.add(openNewFrameButton);

        
        openNewFrameButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
              
                Frame messageFrame = new Frame("Message Frame");
                messageFrame.setSize(250, 150);
                messageFrame.setLayout(new FlowLayout());

                
                Label messageLabel = new Label("Hello! This is a new frame.");
                messageFrame.add(messageLabel);

               
            

                
                messageFrame.setVisible(true);
            }
        });

        
        mainFrame.setVisible(true);
    }

    public static void main(String[] args) {
        new A();
    }
}

