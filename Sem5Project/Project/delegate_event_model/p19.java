import java.awt.Frame;
            import java.awt.Label;
            import java.awt.TextField;
            import java.awt.event.KeyAdapter;
            
            class A  {
                void keyboardevent(){
                    Frame fr=new Frame("KeyBoardEvent");
                    fr.setBounds(0,20,700,700);
                    fr.setLayout(null);
                    Label l=new Label("PLEASE ENTER NUMERICAL PASSWORD: ");
                    fr.add(l);
                    TextField tx= new TextField(10);
                    fr.add(tx);
            
                    l.setBounds(50, 50, 150, 30);
                    tx.setBounds(50, 80, 100, 30);
                   tx.addKeyListener(new KeyAdapter(){
                         public void keyTyped(java.awt.event.KeyEvent e){
                           char ch= e.getKeyChar();
                           if(!Character.isDigit(ch)){
                              e.consume();
                           }
                         }
                   });
               
            
                    fr.setVisible(true);
                }
            
                
                public static void main(String str[]){
                    A obj=new A();
                    obj.keyboardevent();
               
            }
            }