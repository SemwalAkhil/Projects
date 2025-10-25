import java.awt.*;
            import java.awt.event.*;
            
            class A extends Frame {
                public A() {
                    setTitle("Change Background Color to Cyan");
                    setSize(400, 300);
                    setLayout(new FlowLayout());
            
                   
                    setBackground(Color.CYAN);
            
                    
                    Label label = new Label("Background color set to Cyan");
                    add(label);
            
                    
                    
            
                   
                    setVisible(true);
                }
            
                public static void main(String[] args) {
                    new A();
                }
            }