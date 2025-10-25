import java.awt.*;
class A{
    public static void main(String args[]){
        Frame f=new Frame("fonts");
        f.setSize(300,200);
        f.setLayout(new FlowLayout());
        Font font1 = new Font("Serif", Font.PLAIN, 24);
        Font font2 = new Font("SansSerif", Font.BOLD, 28);
        Font font3 = new Font("Monospaced", Font.ITALIC, 26);
        Font font4 = new Font("Dialog", Font.BOLD + Font.ITALIC, 30);
        Label l=new Label("this is Serif");
        l.setFont(font1);
        Label l2=new Label("this is SansSerif");
        l2.setFont(font2);
        Label l3=new Label("this is Monospaced");
        l3.setFont(font3);
        Label l4=new Label("this is Dialog");
        l4.setFont(font4);
        f.add(l);
        f.add(l2);
        f.add(l3);
        f.add(l4);
        f.setVisible(true);
    }
}