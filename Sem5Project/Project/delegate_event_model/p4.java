import java.awt.*;
            import java.awt.event.*;
            
            class Main {
                void RadioBT() {
                    final Frame f = new Frame("Gender Selection");
                    f.setSize(300, 300);
                    f.setLayout(new FlowLayout());
            
                    final Label l = new Label("Select Gender:");
                    final CheckboxGroup cb = new CheckboxGroup();
                    final Checkbox cb1 = new Checkbox("Male", cb, false);
                    final Checkbox cb2 = new Checkbox("Female", cb, false);
                    final Checkbox cb3 = new Checkbox("Other", cb, false);
                    final Button bt = new Button("Submit");
                    final Button bt1 = new Button("Selected choice: None");
            
                    f.add(l);
                    f.add(cb1);
                    f.add(cb2);
                    f.add(cb3);
                    f.add(bt);
                    f.add(bt1);
            
                    
                    bt.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                            Checkbox selectedCheckbox = cb.getSelectedCheckbox();
                            if (selectedCheckbox != null) {
                                String lbl = selectedCheckbox.getLabel();
                                bt1.setLabel("Selected choice: " + lbl);
                            } else {
                                bt1.setLabel("Selected choice: None");
                            }
                        }
                    });
            
                   
                    f.addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent e) {
                            f.dispose();
                        }
                    });
            
                   
                    f.setVisible(true);
                }
            
                public static void main(String st[]) {
                    Main obj = new Main();
                    obj.RadioBT();
                }
            }
            