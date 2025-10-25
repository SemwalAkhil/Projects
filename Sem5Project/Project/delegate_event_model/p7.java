           import java.awt.*;
import java.awt.event.*;

class A {
    public static void main(String[] args) {
      
        Frame frame = new Frame("Checkbox Example");
        frame.setSize(300, 200);
        frame.setLayout(new FlowLayout());

    
        Checkbox checkbox = new Checkbox("Accept Terms and Conditions");
        checkbox.setState(false); 

      
        Button button = new Button("Submit");
        
      
        Label label = new Label();

       
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
              
                boolean isChecked = checkbox.getState();
                String checkboxLabel = checkbox.getLabel();
                
              
                if (isChecked) {
                    label.setText("Checkbox '" + checkboxLabel + "' is checked.");
                } else {
                    label.setText("Checkbox '" + checkboxLabel + "' is unchecked.");
                }
            }
        });

       
        frame.add(checkbox);
        frame.add(button);
        frame.add(label);
        frame.setVisible(true);
    }
}