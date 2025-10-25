            import java.awt.*;
import java.awt.event.*;

class A{
    public static void main(String[] args) {
        
        Frame frame = new Frame("Checkbox and Radio Button Example");
        frame.setSize(400, 300);
        frame.setLayout(null);

       
        Label labelCheckbox = new Label("Select your options:");
        labelCheckbox.setBounds(50, 50, 150, 30);
        Label labelRadioButton = new Label("Select one option:");
        labelRadioButton.setBounds(50, 150, 150, 30);

        
        Checkbox checkbox1 = new Checkbox("Option A");
        checkbox1.setBounds(50, 80, 100, 30);
        Checkbox checkbox2 = new Checkbox("Option B");
        checkbox2.setBounds(50, 110, 100, 30);
        Checkbox checkbox3 = new Checkbox("Option C");
        checkbox3.setBounds(50, 140, 100, 30);

      
        CheckboxGroup radioGroup = new CheckboxGroup();

        
        Checkbox radioButton1 = new Checkbox("Option 1", radioGroup, false);
        radioButton1.setBounds(50, 180, 100, 30);
        Checkbox radioButton2 = new Checkbox("Option 2", radioGroup, false);
        radioButton2.setBounds(50, 210, 100, 30);

       
        frame.add(labelCheckbox);
        frame.add(checkbox1);
        frame.add(checkbox2);
        frame.add(checkbox3);
        frame.add(labelRadioButton);
        frame.add(radioButton1);
        frame.add(radioButton2);

        
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        
        frame.setVisible(true);
    }
}