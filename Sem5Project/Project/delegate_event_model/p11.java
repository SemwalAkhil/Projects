import java.awt.*;
import java.awt.event.*;

class A {
    A() {
    final Frame frame = new Frame("Multi-Select List Example");
        frame.setSize(400, 300);
        frame.setLayout(new FlowLayout());

    
        final Label label = new Label("Select your favorite fruits:");

       
        final List listBox = new List(5, true); 
        listBox.add("Apple");
        listBox.add("Banana");
        listBox.add("Orange");
        listBox.add("Mango");
        listBox.add("Grapes");
        listBox.add("Pineapple");
        listBox.add("Watermelon");

        
        final Button showSelectionButton = new Button("Show Selected Items");

       
        final TextArea selectedItemsArea = new TextArea(5, 30);
        selectedItemsArea.setEditable(false); 
       
        frame.add(label);
        frame.add(listBox);
        frame.add(showSelectionButton);
        frame.add(selectedItemsArea);

       
        showSelectionButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
               
                String[] selectedItems = listBox.getSelectedItems();
                
                
                selectedItemsArea.setText("Selected Items:\n");
                for (String item : selectedItems) {
                    selectedItemsArea.append(item + "\n");
                }
            }
        });

        
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                frame.dispose();
            }
        });

        
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new A();
    }
}